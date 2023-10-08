#include "clases/json.hpp"
#include "clases/class_simulacion.h"
#include "clases/class_randomgenerator.h"
#include "clases/class_cliente.h"
#include "clases/listas/queue.h"
#include "clases/listas/stack.h"

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int Cliente::contadorPedidos = 1;
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
        fila_exterior.enqueue(newCliente);
        cout << "Llego un cliente" << endl;
        this_thread::sleep_for(*tiempoEntreClientes * std::chrono::seconds(1));
    }
}

void bar(int x)
{
    cout << "bar: " << x << endl;
}

int main(void)
{
    thread first (llegadaClientes);     // spawn new thread that calls foo()
    thread second (bar,0);  // spawn new thread that calls bar(0)

    cout << "main, foo and llegada now execute concurrently...\n";

    // synchronize threads:
    first.join(); // pauses until first finishes
    second.join(); // pauses until second finishes

    cout << "llegada and bar completed.\n";

    


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

    return 0;
}