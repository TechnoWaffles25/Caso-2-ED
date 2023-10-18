#ifndef THREADS_H
#define THREADS_H

#include "json.hpp"
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

class threads
{
    private:
        Simulacion simulacion;
        RandomGenerator randomGenerator;    
    public:

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
};
#endif