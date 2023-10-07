#include "listas/lista.h"
#include "JSON.hpp"
#include <iostream>
#include <string>
#include <cstdint>
#include <list>
#include <cstdlib>
#include <nlohmann/json.hpp>

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
        int main() {
            const char* cadena = "123";
            int entero = std::atoi(cadena);

            std::cout << "Valor entero: " << entero << std::endl;

            return 0;
        }

        int main() {
        // Parse a JSON value
        json jsonData = R"(
            {
                "intValue": 42,
                "stringValue": "Hello, JSON!"
            }
        )"_json;

        // Extract and convert JSON values to integers
        int intValue = jsonData["intValue"].get<int>();

        std::cout << "Integer Value: " << intValue << std::endl;

        return 0;
    }

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

        void loadAdditionalData() {
            JSON config;
            config.parseFromFile("config.json");

            auto velocidadParsed = config["velocidad_continuidad"];
            int minimoVelocidad = velocidadParsed["minimo"].toInt();
            int maximoVelocidad = velocidadParsed["maximo"].toInt();
            int intervaloVelocidad = velocidadParsed["intervalo"].toInt();

            auto tiempoAtencionParsed = config["tiempo de atencion segundos"];
            int minimoTiempoAtencion = tiempoAtencionParsed["minimo"].toInt();
            int maximoTiempoAtencion = tiempoAtencionParsed["maximo"].toInt();

            auto tiempoLavaplatosParsed = config["tiempo lavaplatos"];
            int minimoTiempoLavaplatos = tiempoLavaplatosParsed["minimo"].toInt();
            int maximoTiempoLavaplatos = tiempoLavaplatosParsed["maximo"].toInt();

            auto tiempoCocinaParsed = config["tiempo cocina"];
            int minimoTiempoCocina = tiempoCocinaParsed["minimo"].toInt();
            int maximoTiempoCocina = tiempoCocinaParsed["maximo"].toInt();

            auto tiempoMonchonaParsed = config["tiempo monchona"];
            int minimoTiempoMonchona = tiempoMonchonaParsed["minimo"].toInt();
            int maximoTiempoMonchona = tiempoMonchonaParsed["maximo"].toInt();

            cout << "Minimo Velocidad: " << minimoVelocidad << endl;
            cout << "Maximo Velocidad: " << maximoVelocidad << endl;
            cout << "Intervalo Velocidad: " << intervaloVelocidad << endl;
            cout << "Minimo Tiempo de Atención: " << minimoTiempoAtencion << endl;
            cout << "Maximo Tiempo de Atención: " << maximoTiempoAtencion << endl;
            cout << "Minimo Tiempo Lavaplatos: " << minimoTiempoLavaplatos << endl;
            cout << "Maximo Tiempo Lavaplatos: " << maximoTiempoLavaplatos << endl;
            cout << "Minimo Tiempo Cocina: " << minimoTiempoCocina << endl;
            cout << "Maximo Tiempo Cocina: " << maximoTiempoCocina << endl;
            cout << "Minimo Tiempo Monchona: " << minimoTiempoMonchona << endl;
            cout << "Maximo Tiempo Monchona: " << maximoTiempoMonchona << endl;
    }
};