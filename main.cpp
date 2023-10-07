#include <iostream>
#include "clases/json.hpp"
#include "clases/class_simulacion.h"

int main(){
    Simulacion simulacion;
    simulacion.getRandomFood();
    simulacion.getRandomFood();
    simulacion.getRandomFood();
    simulacion.getRandomFood();
    
    simulacion.getRandomName();
    simulacion.getRandomName();
    simulacion.getRandomName();
    simulacion.getRandomName();

    return 0;
}