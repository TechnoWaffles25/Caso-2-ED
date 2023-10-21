#ifndef THREADS_H
#define THREADS_H

#include "json.hpp"
#include "class_simulacion.h"
#include "class_randomgenerator.h"
#include "class_cliente.h"
#include "class_managerCajero.h"
#include "class_cajero.h"
#include "class_managerChefs.h"
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
        ManagerChef* managerChef;
        queue* fila_exterior;
        queue* pedidosPendientes;
        queue* pedidosListos;

    public:
        threads(ManagerCajero* pManagerCajero, ManagerChef* pManagerChef, queue* pFilaExterior, 
                queue* pPedidosPendientes, queue* pPedidosListos, stack* pPlatosLimpios){
            managerCajero = pManagerCajero;
            managerChef = pManagerChef;

            fila_exterior = pFilaExterior;
            pedidosPendientes = pPedidosPendientes;
            pedidosListos = pPedidosListos;
            
        }

        void cargarClientes(){
            this_thread::sleep_for(2s);
            int* tiemopAtencionMin = simulacion.getTiempoAtencionSegMin();
            int* tiemopAtencionMax = simulacion.getTiempoAtencionSegMax();
            while (true) {

                if (!fila_exterior->isEmpty()) {
                    this_thread::sleep_for(4s);
                    // Create a random number generator engine
                    random_device rd;  // Seed the engine
                    mt19937 mt(rd());  // Mersenne Twister pseudo-random number generator
                    uniform_int_distribution<int> distribution(*tiemopAtencionMin,*tiemopAtencionMax);

                    int tiempoRandom = distribution(mt);
                    for (Cajero* cajero : managerCajero->getCajeros()){
                            cout << "Print test" << endl;
                        if (cajero->getClienteActual() == nullptr && !fila_exterior->isEmpty()){
                            cout << "Print test" << endl;
                            Cliente* cliente = static_cast<Cliente*>(fila_exterior->dequeue());
                            cajero->setClienteActual(cliente);
                            cout << "\nEl cajero " << cajero->getName() << " está atendiendo al cliente " << cliente->getName() << endl;
                            Pedido* pedido = cajero->apuntarOrden();
                            this_thread::sleep_for(tiempoRandom * seconds(1));
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
                int* tiempoEntreClientesMin = simulacion.getTiempoEntreClientesMin();
                int* tiempoEntreClientesMax = simulacion.getTiempoEntreClientesMax();

                for (int i = 0; i < *clientAmount; i++)
                {
                    // Create a random number generator engine
                    random_device rd;  // Seed the engine
                    mt19937 mt(rd());  // Mersenne Twister pseudo-random number generator
                    uniform_int_distribution<int> distribution(*tiempoEntreClientesMin, *tiempoEntreClientesMax);
                    int tiempoRandom = distribution(mt);

                    cout << "\n" << endl;
                    Cliente *newCliente = new Cliente();
                    fila_exterior->enqueue(newCliente);
                    cout << "Llego el cliente numero: " << i+1<< endl;
                    
                    this_thread::sleep_for(tiempoRandom * seconds(1));
                }
            }

        void cocinarPedidos(){
            this_thread::sleep_for(2s);
            int* tiempoCocinarMin = simulacion.getTiempoCocinaMin();
            int* tiempoCocinarMax = simulacion.getTiempoCocinaMax();
            while (true) {
                if (!pedidosPendientes->isEmpty()) {
                    this_thread::sleep_for(2s);
                    // Create a random number generator engine
                    random_device rd;  // Seed the engine
                    mt19937 mt(rd());  // Mersenne Twister pseudo-random number generator
                    uniform_int_distribution<int> distribution(*tiempoCocinarMin,*tiempoCocinarMax);
                    int tiempoRandom = distribution(mt);

                    for (Chef* chef : managerChef->getChef()){

                        if (chef->getPedido() == nullptr && !pedidosPendientes->isEmpty()){
                            chef->setPedido();
                            this_thread::sleep_for(2 * seconds(1));
                            cout << "\nEl chef " << chef->getName() << " recibio el pedido " << chef->getPedido()->num_orden << endl;
                            chef->setPlato();
                            this_thread::sleep_for(1 * seconds(1));
                            chef->cocinarPedido();
                            this_thread::sleep_for(tiempoRandom * seconds(1));
                            chef->alistarPedido();
                        }
                    }
                }
                this_thread::sleep_for(50ms);
            }
        }
};
#endif