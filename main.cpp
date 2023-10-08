#include "clases/json.hpp"
#include "clases/class_simulacion.h"
#include "clases/class_randomgenerator.h"
#include "clases/class_cliente.h"
//#include "pthread.h"

#include <iostream>
//#include <pthread.h>
#include <thread>

using namespace std;

int Cliente::contadorPedidos = 1;

/*void *sample(void* arg){
    printf("Thread prueba\n");
}*/
void foo() 
{
  // do stuff...
}

void bar(int x)
{
  // do struff...
}

int main(void)
{
    std::thread first (foo);     // spawn new thread that calls foo()
    std::thread second (bar,0);  // spawn new thread that calls bar(0)

    std::cout << "main, foo and bar now execute concurrently...\n";

    // synchronize threads:
    first.join(); // pauses until first finishes
    second.join(); // pauses until second finishes

    std::cout << "foo and bar completed.\n";

    /*pthread_t tid;
    pthread_create(&tid, NULL, &sample, NULL);
    pthread_join(tid, NULL);*/

    Simulacion simulacion;
    RandomGenerator randomGenerator;


    cout << "------------------------------------" << endl;
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
    cout << cliente3.toString() << endl;

    return 0;
}