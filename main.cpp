#include <iostream>
#include "clases/json.hpp"
#include "clases/class_simulacion.h"
#include "clases/class_randomgenerator.h"
#include "clases/class_cliente.h"
#include <thread>

int Cliente::contadorPedidos = 1;

int main(){
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