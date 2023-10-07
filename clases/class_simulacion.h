#include "listas/lista.h"
#include "json.hpp"
//#include "JSON.hpp"
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

class Simulacion{
    private:
        int* cMinutosSimulacion; // Dado por usuario por el json.
        int* cSegXMinuto; // Dado por usuario por el json.

        int* cClientesPorLlegar; // Dado por usuario por el json.
        int* cTiempoEntreClientes; // Dado por usuario por el json.
        int* cCapacidadRestaurante; // Dado por usuario por el json.

        int* cCajeros; // Dado por usuario por el json.
        int* cCocineros; // Dado por usuario por el json.
        int* cMeseros; // Dado por usuario por el json.
        int* cLavaplatos; // Dado por usuario por el json.
        int* cClientes; // Dado por usuario por el json.
        int* cPlatos; // Dado por usuario por el json.

        int* cTiempoAtencionSegMin; // rango de tiempo determinado en el json
        int* cTiempoAtencionSegMax; // rango de tiempo determinado en el json
        int* cTiempoLavaplatosMin; // rango de tiempo determinado en el json
        int* cTiempoLavaplatosMax; // rango de tiempo determinado en el json
        int* cTiempoCocinaMin; // rango de tiempo determinado en el json
        int* cTiempoCocinaMax; // rango de tiempo determinado en el json
        int* cTiempoMonchonaMin; // rango de tiempo determinado en el json
        int* cTiempoMonchonaMax; // rango de tiempo determinado en el json

        list<string> nombresJSON; // Lista de nombres extraidos del json
        list<string> comidasJSON; // Lista de comidas extraidas del json

    public:
        /*int main() {
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
        }*/

        Simulacion(){
            loadConfig();
        }

        // manejo de configuracion del tiempo de simulacion
        void setMinutosSim(int* parametro){
            cMinutosSimulacion = parametro;
        }
        void setSegXMinuto(int* parametro){
            cSegXMinuto = parametro;
        }

        int* getMinutosSim(){
            return cMinutosSimulacion;
        }
        int* getSegXMinuto(){
            return cSegXMinuto;
        }

        // manejo de configuracion de clientes
        void setClientesPorLlegar(int* parametro){
            cClientesPorLlegar = parametro;
        }
        void setTiempoEntreClientes(int* parametro){
            cTiempoEntreClientes = parametro;
        }
        void setCapacidadRestaurante(int* parametro){
            cCapacidadRestaurante = parametro;
        }

        int* getClientesPorLlegar(){
            return cClientesPorLlegar;
        }
        int* getTiempoEntreClientes(){
            return cTiempoEntreClientes;
        }
        int* getCapacidadRestaurante(){
            return cCapacidadRestaurante;
        }

        // cantidad de empleados por rol
        void setCajeros(int* parametro){
            cCajeros = parametro;
        }
        void setCocineros(int* parametro){
            cCocineros = parametro;
        }
        void setMeseros(int* parametro){
            cMeseros = parametro;
        }
        void setLavaplatos(int* parametro){
            cLavaplatos = parametro;
        }
        void setClientes(int* parametro){
            cClientes = parametro;
        }
        void setPlatos(int* parametro){
            cPlatos = parametro;
        }

        int* getCajeros(){
            return cCajeros;
        }
        int* getCocineros(){
            return cCocineros;
        }
        int* getMeseros(){
            return cMeseros;
        }
        int* getLavaplatos(){
            return cLavaplatos;
        }
        int* getClientes(){
            return cClientes;
        }
        int* getPlatos(){
            return cPlatos;
        }

        // rangos de tiempo de atencion de cada empleado para su actividad
        void setTiempoAtencionSegMin(int* parametro){
            cTiempoAtencionSegMin = parametro;
        }
        void setTiempoAtencionSegMax(int* parametro){
            cTiempoAtencionSegMax = parametro;
        }
        void setTiempoLavaplatosMin(int* parametro){
            cTiempoLavaplatosMin = parametro;
        }
        void setTiempoLavaplatosMax(int* parametro){
            cTiempoLavaplatosMax = parametro;
        }
        void setTiempoCocinaMin(int* parametro){
            cTiempoCocinaMin = parametro; 
        }
        void setTiempoCocinaMax(int* parametro){
            cTiempoCocinaMax = parametro;
        }
        void setTiempoMonchonaMin(int* parametro){
            cTiempoMonchonaMin = parametro;
        }
        void setTiempoMonchonaMax(int* parametro){
            cTiempoMonchonaMax = parametro;
        }
        
        int* getTiempoAtencionSegMin(){
            return cTiempoAtencionSegMin;
        }
        int* getTiempoAtencionSegMax(){
            return cTiempoAtencionSegMax;
        }
        int* getTiempoLavaplatosMin(){
            return cTiempoLavaplatosMin;
        }
        int* getTiempoLavaplatosMax(){
            return cTiempoLavaplatosMax;
        }
        int* getTiempoCocinaMin(){
            return cTiempoCocinaMin;
        }
        int* getTiempoCocinaMax(){
            return cTiempoCocinaMax;
        }
        int* getTiempoMonchonaMin(){
            return cTiempoMonchonaMin;
        }
        int* getTiempoMonchonaMax(){
            return cTiempoMonchonaMax;
        }

        // Cargamos la configuracion del json
        void loadConfig() {
            ifstream file("config.json");
            json data;
            file >> data;

            cMinutosSimulacion = new int(data["minutos simulacion"].get<int>());
            cSegXMinuto = new int(data["segundos por minuto"].get<int>());

            cClientesPorLlegar = new int(data["clientes por llegar"].get<int>());
            cTiempoEntreClientes = new int(data["tiempo entre clientes"].get<int>());
            cCapacidadRestaurante = new int(data["capacidad restaurante"].get<int>());

            cCajeros = new int(data["cajeros"].get<int>());
            cCocineros = new int(data["cocineros"].get<int>());
            cLavaplatos = new int(data["lavaplatos"].get<int>());
            cMeseros = new int(data["meseros"].get<int>());
            cPlatos = new int(data["platos"].get<int>());

            cTiempoAtencionSegMin = new int(data["tiempo en caja"]["minimo"].get<int>());
            cTiempoAtencionSegMax = new int(data["tiempo en caja"]["maximo"].get<int>());
            cTiempoLavaplatosMin = new int(data["tiempo lavaplatos"]["minimo"].get<int>());
            cTiempoLavaplatosMax = new int(data["tiempo lavaplatos"]["maximo"].get<int>());
            cTiempoCocinaMin = new int(data["tiempo cocina"]["minimo"].get<int>());
            cTiempoCocinaMax = new int(data["tiempo cocina"]["maximo"].get<int>());
            cTiempoMonchonaMin = new int(data["tiempo monchona"]["minimo"].get<int>());
            cTiempoMonchonaMax = new int(data["tiempo monchona"]["maximo"].get<int>());
            
            // Setteamos los valores
            setMinutosSim(cMinutosSimulacion);
            setSegXMinuto(cSegXMinuto);
            
            setClientesPorLlegar(cClientesPorLlegar);
            setTiempoEntreClientes(cTiempoEntreClientes);
            setCapacidadRestaurante(cCapacidadRestaurante);

            setCajeros(cCajeros);
            setCocineros(cCocineros);
            setMeseros(cMeseros);
            setLavaplatos(cLavaplatos);
            setPlatos(cPlatos);

            setTiempoAtencionSegMin(cTiempoAtencionSegMin);
            setTiempoAtencionSegMax(cTiempoAtencionSegMax);
            setTiempoLavaplatosMin(cTiempoLavaplatosMin);
            setTiempoLavaplatosMax(cTiempoLavaplatosMax);
            setTiempoCocinaMin(cTiempoCocinaMin);
            setTiempoCocinaMax(cTiempoCocinaMax);
            setTiempoMonchonaMin(cTiempoMonchonaMin);
            setTiempoMonchonaMax(cTiempoMonchonaMax);

            // Cargamos los nombres
            for (auto& nombre : data["nombres"]) {
                nombresJSON.push_back(nombre.get<string>());
            }
            // Cargamos las comidas
            for (auto& comida : data["comidas"]) {
                comidasJSON.push_back(comida.get<string>());
            }

            cout << "Configuracion cargada exitosamente" << endl;

            cout << "Minutos de simulacion: " << *getMinutosSim() << endl;
            cout << "Segundos por minuto: " << *getSegXMinuto() << endl;
            cout << "Clientes por llegar: " << *getClientesPorLlegar() << endl;
            cout << "Tiempo entre clientes: " << *getTiempoEntreClientes() << endl;
            cout << "Capacidad restaurante: " << *getCapacidadRestaurante() << endl;
            cout << "Cajeros: " << *getCajeros() << endl;
            cout << "Cocineros: " << *getCocineros() << endl;
            cout << "Meseros: " << *getMeseros() << endl;
            cout << "Lavaplatos: " << *getLavaplatos() << endl;
            cout << "Platos: " << *getPlatos() << endl;
            cout << "Tiempo atencion seg min: " << *getTiempoAtencionSegMin() << endl;
            cout << "Tiempo atencion seg max: " << *getTiempoAtencionSegMax() << endl;
            cout << "Tiempo lavaplatos min: " << *getTiempoLavaplatosMin() << endl;
            cout << "Tiempo lavaplatos max: " << *getTiempoLavaplatosMax() << endl;
            cout << "Tiempo cocina min: " << *getTiempoCocinaMin() << endl;
            cout << "Tiempo cocina max: " << *getTiempoCocinaMax() << endl;
            cout << "Tiempo monchona min: " << *getTiempoMonchonaMin() << endl;
            cout << "Tiempo monchona max: " << *getTiempoMonchonaMax() << endl;
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