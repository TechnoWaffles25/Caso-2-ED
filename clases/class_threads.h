#ifndef THREADS_H
#define THREADS_H

#include "json.hpp"
#include "class_simulacion.h"
#include "class_randomgenerator.h"
#include "class_cliente.h"
#include "class_managerCajero.h"
#include "class_cajero.h"
#include "listas/queue.h"
#include "listas/stack.h"
#include <random>


#include <iostream>
#include <thread>
#include <chrono>
#include <condition_variable>
#include <mutex>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;
using namespace nlohmann::json_literals;

class threads
{
    private:
        Simulacion simulacion;
        RandomGenerator randomGenerator;
        ManagerCajero* managerCajero;
        queue* fila_exterior;

    public:
        threads(ManagerCajero* pManagerCajero, queue* pFilaExterior){
            managerCajero = pManagerCajero;
            fila_exterior = pFilaExterior;
        }
        void cargarClientes(){
            this_thread::sleep_for(2s);
            cout << "Entro a cargar clientes" << endl;

            while (true) {

                if (!fila_exterior->isEmpty()) {
                    this_thread::sleep_for(4s);
                    for (Cajero* cajero : managerCajero->getCajeros()){

                        if (cajero->getClienteActual() == nullptr && !fila_exterior->isEmpty()){
                            Cliente* cliente = static_cast<Cliente*>(fila_exterior->dequeue());
                            cajero->setClienteActual(cliente);
                            cout << "\nEl cajero " << cajero->getName() << " está atendiendo al cliente " << cliente->getName() << endl;
                            Pedido* pedido = cajero->apuntarOrden();
                            this_thread::sleep_for(4s);
                            cajero->comunicarOrden(pedido);
                        }
                    }
                }
                this_thread::sleep_for(50ms);
            }
        }

        void llegadaClientes() 
            {   
                int* clientAmount = simulacion.getClientesPorLlegar();
                int* tiempoEntreClientes = simulacion.getTiempoEntreClientes();

                for (int i = 0; i < *clientAmount; i++)
                {
                    cout << "\n" << endl;
                    Cliente *newCliente = new Cliente();
                    fila_exterior->enqueue(newCliente);
                    cout << "Llego el cliente numero: " << i+1<< endl;
                    
                    this_thread::sleep_for(*tiempoEntreClientes * seconds(1));
                }
            }
};
#endif