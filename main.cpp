#include <iostream>
#include <nlohmann/json.hpp>
#include "json.hpp"
#include "clases/class_simulacion.h"

int main(){
    Simulacion simulacion;
    simulacion.loadConfig();
    return 0;
}