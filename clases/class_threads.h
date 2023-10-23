#ifndef THREADS_H
#define THREADS_H

#include "json.hpp"
#include "class_simulacion.h"
#include "class_randomgenerator.h"
#include "class_cliente.h"
#include "class_managerCajero.h"
#include "class_cajero.h"
#include "class_managerChefs.h"
#include "class_managerMeseros.h"
#include "listas/queue.h"
#include "listas/stack.h"
#include <list>
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
        ManagerMesero* managerMesero;

        queue* fila_exterior;
        queue* pedidosPendientes;
        queue* pedidosListos;

        vector<Cliente*> restaurante;
        vector<Plato*> platosSuciosRestaurante;

    public:
        threads(ManagerCajero* pManagerCajero, ManagerChef* pManagerChef, ManagerMesero* pManagerMesero, queue* pFilaExterior, 
                queue* pPedidosPendientes, queue* pPedidosListos, stack* pPlatosLimpios, 
                vector<Cliente*>  pRestaurante, vector<Plato*> pPlatosSuciosRestaurante){
            managerCajero = pManagerCajero;
            managerChef = pManagerChef;

            fila_exterior = pFilaExterior;
            restaurante = pRestaurante;

            pedidosPendientes = pPedidosPendientes;
            pedidosListos = pPedidosListos;
        }

        void cargarClientes(){
            this_thread::sleep_for(2s);
            int* tiemopAtencionMin = simulacion.getTiempoAtencionSegMin();
            int* tiemopAtencionMax = simulacion.getTiempoAtencionSegMax();
            // Create a random number generator engine
            random_device rd;  // Seed the engine
            mt19937 mt(rd());  // Mersenne Twister pseudo-random number generator
            while (true) {
                if (!fila_exterior->isEmpty()) {
                    this_thread::sleep_for(4s);       
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
                // Create a random number generator engine
                random_device rd;  // Seed the engine
                mt19937 mt(rd());  // Mersenne Twister pseudo-random number generator
                for (int i = 0; i < *clientAmount; i++)
                {
                    uniform_int_distribution<int> distribution(*tiempoEntreClientesMin, *tiempoEntreClientesMax);
                    int tiempoRandom = distribution(mt);

                    cout << "\n" << endl;
                    Cliente *newCliente = new Cliente(platosSuciosRestaurante);
                    fila_exterior->enqueue(newCliente);
                    cout << "Llego el cliente numero: " << i+1<< endl;
                    
                    this_thread::sleep_for(tiempoRandom * seconds(1));
                }
            }

        void cocinarPedidos(){
            this_thread::sleep_for(2s);
            int* tiempoCocinarMin = simulacion.getTiempoCocinaMin();
            int* tiempoCocinarMax = simulacion.getTiempoCocinaMax();
            // Create a random number generator engine
            random_device rd;  // Seed the engine
            mt19937 mt(rd());  // Mersenne Twister pseudo-random number generator
            while (true) {
                if (!pedidosPendientes->isEmpty()) {
                    this_thread::sleep_for(2s);

                    uniform_int_distribution<int> distribution(*tiempoCocinarMin,*tiempoCocinarMax);
                    int tiempoRandom = distribution(mt);
                    cout << "Print test 1" << endl;
                    for (Chef* chef : managerChef->getChef()){
                        cout << "Print test 2" << endl;
                        if (chef->getPedido() == nullptr && !pedidosPendientes->isEmpty()){
                            cout << "Print test 3" << endl;
                            chef->setPedido();
                            this_thread::sleep_for(2 * seconds(1));
                            cout << "\nEl chef " << chef->getName() << " recibio el pedido " << chef->getPedido()->num_orden << endl;
                            chef->setPlato();
                            cout << "Print test 4" << endl;
                            this_thread::sleep_for(1 * seconds(1));
                            chef->cocinarPedido();
                            cout << "Print test 5" << endl;
                            this_thread::sleep_for(tiempoRandom * seconds(1));
                            cout << "El chef esta alistando el pedido " << endl;
                            chef->alistarPedido();
                            cout << "Print test 6" << endl;
                            this_thread::sleep_for(2 * seconds(1));
                        }
                    }
                }
                this_thread::sleep_for(50ms);
            }
        }

        void servirPedido(){
            this_thread::sleep_for(2s);
            while (true) {
                if (pedidosListos->isEmpty()==false) {
                    for (Mesero* mesero : managerMesero->getMesero()){
                        if (!pedidosListos->isEmpty()){
                            mesero->servirOrden();
                            this_thread::sleep_for(3s);
                        }
                    }
                }
                this_thread::sleep_for(1s);
            }
        }

        void clienteComer(){
            this_thread::sleep_for(2s);
            int* tiempoComerMin = simulacion.getTiempoMonchonaMin();
            int* tiempoComerMax = simulacion.getTiempoMonchonaMax();
            // Create a random number generator engine
            random_device rd;  // Seed the engine
            mt19937 mt(rd());  // Mersenne Twister pseudo-random number generator
            while (true) {
                if (!restaurante.empty()) {
                    this_thread::sleep_for(2s);
                    for (Cliente* cliente : restaurante){
                        if (cliente->getPedido() != nullptr && *(cliente->getPedido()->listo) == true){
                            uniform_int_distribution<int> distribution(*tiempoComerMin,*tiempoComerMax);
                            int tiempoRandom = distribution(mt);
                            cliente->comerMoncha();
                            this_thread::sleep_for(tiempoRandom * seconds(3));
                        }
                    }
                }
                this_thread::sleep_for(1ms);
            }
        }
};
#endif