#include "clases/json.hpp"
#include "clases/class_simulacion.h"
#include "clases/class_randomgenerator.h"
#include "clases/class_cliente.h"
#include "clases/class_cajero.h"
#include "clases/listas/queue.h"
#include "clases/listas/stack.h"
#include <random>


#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int Cliente::contadorPedidos = 1;
int Cliente::contadorPedidos2 = 1;

Simulacion simulacion;
RandomGenerator randomGenerator;

void llegadaClientes() 
{   
    using namespace std::literals::chrono_literals;

    int* clientAmount = simulacion.getClientesPorLlegar();
    int* tiempoEntreClientes = simulacion.getTiempoEntreClientes();

    for (int i = 0; i < *clientAmount; i++)
    {
        Cliente *newCliente = new Cliente();
        cout << "\nLlego un cliente" << endl;
        fila_exterior.enqueue(newCliente);
        this_thread::sleep_for(*tiempoEntreClientes * std::chrono::seconds(1));
    }
}

void operationCajero()
{   
    using namespace std::literals::chrono_literals;

    vector<Cajero*> cajeros;
    int* numCajeros = simulacion.getCajeros();

    int* atencionCajeroMin = simulacion.getTiempoAtencionSegMin();
    int* atencionCajerMax = simulacion.getTiempoAtencionSegMax();

    for (int i = 0; i < *numCajeros; i++)
    {
        string cajeroName = "Cajero " + to_string(i + 1);
        Cajero* newCajero = new Cajero(cajeroName);
        cajeros.push_back(newCajero);
        cout << "\nSe ha creado un cajero llamado " << newCajero->getName() << endl;
    }

    while (!fila_exterior.isEmpty()) {
    for (int i = 0; i < *numCajeros && !fila_exterior.isEmpty(); i++) {
        cout << "\nCajero " << i << " está sirviendo." << endl;
        void* ptr = fila_exterior.dequeue();
        Cliente* cliente = static_cast<Cliente*>(ptr);
        cajeros[i]->setClienteActual(cliente);
        cajeros[i]->atenderCliente();
        int serveTime = 5;
        this_thread::sleep_for(serveTime * std::chrono::seconds(1));
        Pedido* pedido = cajeros[i]->apuntarOrden();
        cajeros[i]->comunicarOrden(pedido);
    }
}
cout << "Todos los clientes fueron servidos" << endl;
}


int main(void)
{
    // Create a thread for the llegadaClientes() function
    thread clientesThread(llegadaClientes);

    // Create a thread for the operationCajero() function
    thread cajeroThread(operationCajero);

    // Wait for both threads to finish
    clientesThread.join();
    cajeroThread.join();
    
    /*cout << "------------------------------------" << endl;
    randomGenerator.getRandomFood();
    randomGenerator.getRandomFood();
    randomGenerator.getRandomFood();
    randomGenerator.getRandomFood();
    cout << "------------------------------------" << endl;
    randomGenerator.getRandomName();
    randomGenerator.getRandomName();
    randomGenerator.getRandomName();
    randomGenerator.getRandomName();

    cout << "------------------------------------" << endl;
    Cliente cliente1 = Cliente();
    Cliente cliente2 = Cliente();
    Cliente cliente3 = Cliente();

    cout << "------------------------------------" << endl;
    cout << cliente1.toString() << endl;
    cout << "------------------------------------" << endl;
    cout << cliente2.toString() << endl;
    cout << "------------------------------------" << endl;
    cout << cliente3.toString() << endl;*/
}