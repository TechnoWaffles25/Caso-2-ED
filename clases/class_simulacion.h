#include "listas/lista.h"
#include "JSON.hpp"
#include <iostream>
#include <string>
#include <cstdint>
#include <list>

using JSON = dnc::JSON;
using namespace std;

class Simulacion{

    // La cantidad de meseros, cajeros, cocineros y clientes
    private:
        int cClientesNuevos; // Random extraido del rango de la velocidad del json.
        int cVelocidad; // Extraido del json, fijo.

        int cCajeros; // Dado por usuario
        int cCocineros; // Dado por usuario
        int cMeseros; // Dado por usuario
        int cClientes; // Dado por usuario

        int cPlatos; // Dado por el usuario
        int vector_restaurante; // Dado por el usuario, cantidad maxima de personas en el restaurante

        int cTiempoAtencionSeg; // rango de tiempo determinado en el json
        int cTiempoLavaplatos; // rango de tiempo determinado en el json
        int cTiempoCocina; // rango de tiempo determinado en el json
        int cTiempoMonchona; // rango de tiempo determinado en el json

        list<string> nombresJSON; // Lista de nombres extraidos del json
        list<string> comidasJSON; // Lista de comidas extraidas del json

    public:
        Simulacion(int pTiempoEscala, int pCajeros, int pCocineros, int pMeseros, int pPlatos, int pVectorRestaurante){
            loadConfig();
            // Cargamos las variables con los setters o tambien como parametro fijo dado por el usuario
        }
        int setTiempoEscalaSeg(int parametro){
            // logica
        }
        int setCajeros(int parametro){
            // logica de validacion
        }
        int setCocineros(int parametro){
            // logica de validacion
        }
        int setMeseros(int parametro){
            // logica de validacion
        }
        int setPlatos(int parametro){
            // logica de validacion
        }
        int setVectorRestaurante(int parametro){
            // Logica de validacon
        }
        int setTiempoAtencionSeg(int parametro){
            // logica que restringe los valores a los que estan en el json 
        }
        int setTiempoLavaplatos(int parametro){
            // logica que restringe los valores a los que estan en el json 
        }
        int setTiempoCocina(int parametro){
            // logica que restringe los valores a los que estan en el json 
        }
        int setTiempoMonchona(int parametro){
            // logica que restringe los valores a los que estan en el json 
        }
        
        void loadConfig(){
            JSON config;
            config.parseFromFile("config.json");
            //cout << "Parsed JSON: " << config.toString() << endl;

            auto nombresParsed = config["nombres"];
            auto comidasParsed = config["productos"];
            //cout << nombres["nombres"].toString() << endl;
            //cout << comidas["productos"].toString() << endl;
                    
            for (auto& nombre : nombresParsed){
                nombresJSON.push_back(nombre.toString()); // Convert the JSON object to a string before adding it to the list
            }

            for (auto& comida : comidasParsed){
                comidasJSON.push_back(comida.toString()); // Convert the JSON object to a string before adding it to the list
            }
            cout << "Size nombres list: " << nombresJSON.size() << endl;
            cout << "Size comidas list: " << comidasJSON.size() << endl;
        }
};