#include <lista.h>
#include <JSON.hpp>
#include <iostream>

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

        int cTiempoAtencionSeg; // json
        int cTiempoLavaplatos; // json
        int cTiempoCocina; // json
        int cTiempoMonchona; // json

        listadoble nombres; // Lista de nombres extraidos del json
        listadoble comidas; // Lista de comidas extraidas del json

    public:
        Simulacion(){
            // Read Json, extract variables
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
            // logica que restringe los valores a los que estan en el json 
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
        
        void loadNombres(){
            JSON nombres;
            nombres.parseFromFile("nombres.json");
        }
        void loadComidas(){
            // Carga las comidas del json a la lista comidas
        }
};