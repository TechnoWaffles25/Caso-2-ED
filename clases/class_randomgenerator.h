#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include "listas/lista.h"
#include "json.hpp"
#include <iostream>
#include <string>
#include <cstdint>
#include <fstream>
#include <list>
#include <cstdlib>
#include <random>

using json = nlohmann::json;
using namespace std;

/*  To get the integer value of the attributes we need to derefernce the pointer that is returned by the getter
 
    int* Platos = simulacion.getPlatos();
    int platos = *platosPtr;

*/

class RandomGenerator {
    private:
        list<string> nombresJSON; // Lista de nombres extraidos del json
        list<string> comidasJSON; // Lista de comidas extraidas del json
    public:
        RandomGenerator(){
            cargarNombresComidas();
        }

        void cargarNombresComidas(){
            ifstream file("config.json");
            json data;
            file >> data;

            for (auto& nombre : data["nombres"]) {
                nombresJSON.push_back(nombre.get<string>());
            }

            for (auto& comida : data["comidas"]) {
                comidasJSON.push_back(comida.get<string>());
            }
        }

        string getRandomName(){
            if (nombresJSON.empty()){
                cout << "No hay nombres en el json" << endl;
                return "";
            }
            
            // Generamos un numero aleatorio
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> dis(0, nombresJSON.size()-1);

            // Obtenemos el indice random
            int random = dis(gen);
            
            // obtenemos el nombre en ese indice
            string randomName = *next(nombresJSON.begin(), random);
            cout << "Nombre: " << randomName << endl;
            return randomName;
        }

        string getRandomFood(){
            if(comidasJSON.empty()){
                cout << "No hay comidas en el json" << endl;
                return "";
            }

            // Generamos un numero aleatorio
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> dis(0, comidasJSON.size()-1);

            // Obtenemos el indice random
            int random = dis(gen);
            
            // obtenemos el nombre en ese indice
            string randomFood = *next(comidasJSON.begin(), random);
            cout << "Comida: " << randomFood << endl;
            return randomFood;
        }
};
#endif // RANDOMGENERATOR_H