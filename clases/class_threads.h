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
#include "class_managerLavaplatos.h"
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
        ManagerLavaplatos* managerLavaplatos;

        queue* fila_exterior;
        queue* pedidosPendientes;
        queue* pedidosListos;

        stack* platosLimpios;
        stack* platosSucios;

        vector<Cliente*> restaurante;

    public:
        threads(ManagerCajero* pManagerCajero, ManagerChef* pManagerChef, ManagerMesero* pManagerMesero, queue* pFilaExterior, 
                queue* pPedidosPendientes, queue* pPedidosListos, stack* pPlatosLimpios, stack* pPlatosSucios, 
                vector<Cliente*>  pRestaurante){
            managerCajero = pManagerCajero;
            managerChef = pManagerChef;
            managerMesero = pManagerMesero;

            fila_exterior = pFilaExterior;
            restaurante = pRestaurante;

            platosLimpios = pPlatosLimpios;
            platosSucios = pPlatosSucios;

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
                        if (cajero->getClienteActual() == nullptr && !fila_exterior->isEmpty()){
                            Cliente* cliente = static_cast<Cliente*>(fila_exterior->dequeue());
                            cajero->setClienteActual(cliente);
                            cout << "\nTHRD - El cajero " << cajero->getName() << " está atendiendo al cliente " << cliente->getName() << endl;
                            Pedido* pedido = cajero->apuntarOrden();
                            this_thread::sleep_for(tiempoRandom * seconds(1));
                            restaurante.push_back(cliente);
                            cout << "Pushback" << endl;
                            cout << "\nTHRD - Clients in the restaurant: " << restaurante.size() << endl;
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
                    Cliente *newCliente = new Cliente(platosSucios);
                    fila_exterior->enqueue(newCliente);
                    cout << "\nTHRD - Llego el cliente numero: " << i+1<< endl;
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
                    for (Chef* chef : managerChef->getChef()){
                        if (chef->getPedido() == nullptr && !pedidosPendientes->isEmpty()){
                            chef->setPedido();
                            this_thread::sleep_for(2 * seconds(1));
                            cout << "\nTHRD - El chef " << chef->getName() << " recibio el pedido " << chef->getPedido()->num_orden << endl;
                            chef->setPlato();
                            this_thread::sleep_for(1 * seconds(1));
                            chef->cocinarPedido();
                            this_thread::sleep_for(tiempoRandom * seconds(1));
                            cout << "\nTHRD - El chef esta alistando el pedido " << endl;
                            chef->alistarPedido();
                            this_thread::sleep_for(2 * seconds(1));
                        }
                    }
                }
                this_thread::sleep_for(50ms);
            }
        }

        void servirPedido(){
            this_thread::sleep_for(8s);
            while (true) {
                if (pedidosListos->isEmpty()==false) {
                    for (Mesero* mesero : managerMesero->getMesero()){
                        if (!pedidosListos->isEmpty()){
                            cout << "MESERO - El mesero "<< mesero->getName() << " esta recogiendo un pedido" << endl;
                            Pedido* pedido = static_cast<Pedido*>(pedidosListos->dequeue());
                            cout << "MESERO - El mesero " << mesero->getName()<< " agarro el pedido " << *pedido->num_orden << endl;
                            cout << "RESTAURANTE SIZE " << restaurante.size() << endl;
                            for (int i = 0; i < restaurante.size(); i++) {
                                Cliente* cliente = restaurante.at(i);
                                if (*cliente->getNumeroOrdenPtr() == *pedido->num_orden) {
                                    cliente->setPedido(pedido);
                                    cout << "MESERO - El mesero " << mesero->getName() << " le ha servido el pedido " << pedido << " al cliente " << cliente->getName() << endl;
                                    this_thread::sleep_for(3s);
                                    break;
                                }
                            }
                        }
                    }
                }
                this_thread::sleep_for(2s);
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
                    for (int i = 0; i < restaurante.size(); i++) {
                        Cliente* cliente = restaurante[i];
                        cout << "PRUEBA" << endl;
                        if (cliente->getPedido() != nullptr && *(cliente->getPedido()->listo) == true){
                            cout << "PRUEBA 2" << endl;
                            uniform_int_distribution<int> distribution(*tiempoComerMin,*tiempoComerMax);
                            int tiempoRandom = distribution(mt);
                            cliente->comerMoncha();
                            restaurante.erase(restaurante.begin() + i); // Remove the element at index i
                            this_thread::sleep_for(tiempoRandom * seconds(3));
                            i--; // Decrement the index to account for the removed element
                        }
                    }
                }
                this_thread::sleep_for(1s);
            }
        }

        void lavarPlatos(){
            while (true){
                int* tiempoLimpiarMin = simulacion.getTiempoLavaplatosMin();
                int* tiempoLimpiarMax = simulacion.getTiempoLavaplatosMax();
                // Create a random number generator engine
                random_device rd;  // Seed the engine
                mt19937 mt(rd());  // Mersenne Twister pseudo-random number generator
                uniform_int_distribution<int> distribution(*tiempoLimpiarMin,*tiempoLimpiarMax);
                if (!platosSucios->isEmpty()){
                    this_thread::sleep_for(2s);
                    for (Lavaplatos* lavaplatos : managerLavaplatos->getLavaplatos()){
                        int tiempoRandom = distribution(mt);
                        cout << "PRUEBA LAVAPLATOS 1" << endl;
                        if (!platosSucios->isEmpty()) {
                            cout << "PRUEBA LAVAPLATOS 2" << endl;
                            void* platoVoid = platosSucios->pop();
                            Plato* platoSucio = static_cast<Plato*>(platoVoid);
                            // Simular el proceso de lavado
                            cout << "LVPTS - El lavaplatos " << lavaplatos->getName() << " está lavando el plato " << platoSucio->getName() << std::endl;
                            // Cambiar el estado del plato a limpio
                            platoSucio->cambiarLimpio();
                            // Colocar el plato limpio en la pila de platos limpios
                            platosLimpios->push(platoSucio);
                            cout << "LVPTS - El plato " << platoSucio->getName() << " está limpio" << std::endl;
                        }
                        this_thread::sleep_for(tiempoRandom * seconds(1));
                    }
                }
                this_thread::sleep_for(50ms);
            }
        }
};
#endif