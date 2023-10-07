#include "listas/lista.h"
#include "json.hpp"
//#include "JSON.hpp"
#include <iostream>
#include <string>
#include <cstdint>
#include <fstream>
#include <list>
#include <cstdlib>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

class Simulacion{

    // La cantidad de meseros, cajeros, cocineros y clientes
    private:
        int cMinutosSimulacion; // Dado por usuario por el json.
        int cSegXMinuto; // Dado por usuario por el json.

        int cClientesPorLlegar; // Dado por usuario por el json.
        int cTiempoEntreClientes; // Dado por usuario por el json.
        int cCapacidadRestaurante; // Dado por usuario por el json.

        int cCajeros; // Dado por usuario por el json.
        int cCocineros; // Dado por usuario por el json.
        int cMeseros; // Dado por usuario por el json.
        int cClientes; // Dado por usuario por el json.
        int cPlatos; // Dado por usuario por el json.

        int cTiempoAtencionSegMin; // rango de tiempo determinado en el json
        int cTiempoAtencionSegMax; // rango de tiempo determinado en el json
        int cTiempoLavaplatosMin; // rango de tiempo determinado en el json
        int cTiempoLavaplatosMax; // rango de tiempo determinado en el json
        int cTiempoCocinaMin; // rango de tiempo determinado en el json
        int cTiempoCocinaMax; // rango de tiempo determinado en el json
        int cTiempoMonchonaMin; // rango de tiempo determinado en el json
        int cTiempoMonchonaMax; // rango de tiempo determinado en el json

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
        void setMinutosSim(int parametro){
            cMinutosSimulacion = parametro;
        }
        void setSegXMinuto(int parametro){
            cSegXMinuto = parametro;
        }

        int getMinutosSim(){
            return cMinutosSimulacion;
        }
        int getSegXMinuto(){
            return cSegXMinuto;
        }

        // manejo de configuracion de clientes
        void setClientesPorLlegar(int parametro){
            cClientesPorLlegar = parametro;
        }
        void setTiempoEntreClientes(int parametro){
            cTiempoEntreClientes = parametro;
        }
        void setCapacidadRestaurante(int parametro){
            cCapacidadRestaurante = parametro;
        }

        int getClientesPorLlegar(){
            return cClientesPorLlegar;
        }
        int getTiempoEntreClientes(){
            return cTiempoEntreClientes;
        }
        int getCapacidadRestaurante(){
            return cCapacidadRestaurante;
        }

        // cantidad de empleados por rol
        void setCajeros(int parametro){
            cCajeros = parametro;
        }
        void setCocineros(int parametro){
            cCocineros = parametro;
        }
        void setMeseros(int parametro){
            cMeseros = parametro;
        }
        void setClientes(int parametro){
            cClientes = parametro;
        }
        void setPlatos(int parametro){
            cPlatos = parametro;
        }

        int getCajeros(){
            return cCajeros;
        }
        int getCocineros(){
            return cCocineros;
        }
        int getMeseros(){
            return cMeseros;
        }
        int getClientes(){
            return cClientes;
        }
        int getPlatos(){
            return cPlatos;
        }

        // rangos de tiempo de atencion de cada empleado para su actividad
        void setTiempoAtencionSegMin(int parametro){
            cTiempoAtencionSegMin = parametro;
        }
        void setTiempoAtencionSegMax(int parametro){
            cTiempoAtencionSegMax = parametro;
        }
        void setTiempoLavaplatosMin(int parametro){
            cTiempoLavaplatosMin = parametro;
        }
        void setTiempoLavaplatosMax(int parametro){
            cTiempoLavaplatosMax = parametro;
        }
        void setTiempoCocinaMin(int parametro){
            cTiempoCocinaMin = parametro; 
        }
        void setTiempoCocinaMax(int parametro){
            cTiempoCocinaMax = parametro;
        }
        void setTiempoMonchonaMin(int parametro){
            cTiempoMonchonaMin = parametro;
        }
        void setTiempoMonchonaMax(int parametro){
            cTiempoMonchonaMax = parametro;
        }
        
        int getTiempoAtencionSegMin(){
            return cTiempoAtencionSegMin;
        }
        int getTiempoAtencionSegMax(){
            return cTiempoAtencionSegMax;
        }
        int getTiempoLavaplatosMin(){
            return cTiempoLavaplatosMin;
        }
        int getTiempoLavaplatosMax(){
            return cTiempoLavaplatosMax;
        }
        int getTiempoCocinaMin(){
            return cTiempoCocinaMin;
        }
        int getTiempoCocinaMax(){
            return cTiempoCocinaMax;
        }
        int getTiempoMonchonaMin(){
            return cTiempoMonchonaMin;
        }
        int getTiempoMonchonaMax(){
            return cTiempoMonchonaMax;
        }

        // Cargamos la configuracion del json
        void Simulacion::loadConfig() {
            std::ifstream file("config.json");
            json data;
            file >> data;

            cMinutosSimulacion = data["minutos"].get<int>();
            cSegXMinuto = data["segundos por minuto"].get<int>();

            cClientesPorLlegar = data["clientes por llegar"].get<int>();
            cTiempoEntreClientes = data["tiempo entre clientes"].get<int>();
            cCapacidadRestaurante = data["capacidad restaurante"].get<int>();

            cCajeros = data["cajeros"].get<int>();
            cCocineros = data["cocineros"].get<int>();
            cMeseros = data["meseros"].get<int>();
            cPlatos = data["platos"].get<int>();

            cTiempoAtencionSegMin = data["tiempo atencion seg min"].get<int>();
            cTiempoAtencionSegMax = data["tiempo atencion seg max"].get<int>();
            cTiempoLavaplatosMin = data["tiempo lavaplatos seg min"].get<int>();
            cTiempoLavaplatosMax = data["tiempo lavaplatos seg max"].get<int>();
            cTiempoCocinaMin = data["tiempo cocina seg min"].get<int>();
            cTiempoCocinaMax = data["tiempo cocina seg max"].get<int>();
            cTiempoMonchonaMin = data["tiempo monchona seg min"].get<int>();
            cTiempoMonchonaMax = data["tiempo monchona seg max"].get<int>();
            
            // Setteamos los valores
            setMinutosSim(cMinutosSimulacion);
            setSegXMinuto(cSegXMinuto);
            
            setClientesPorLlegar(cClientesPorLlegar);
            setTiempoEntreClientes(cTiempoEntreClientes);
            setCapacidadRestaurante(cCapacidadRestaurante);

            setCajeros(cCajeros);
            setCocineros(cCocineros);
            setMeseros(cMeseros);
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
        }
};