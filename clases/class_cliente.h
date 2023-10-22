#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <sstream>
#include "class_randomgenerator.h"
#include "class_plato.h"
#include "struct_pedido.h"
using namespace std;
class Cliente
{
    private:
        string name; /* Nombre sacado de la lista json */
        string item; /* obtenido por la funcion decidirPedido */ // PRIMERAMENTE ES NULL
        int* numeroOrden; /* Se settea con la funcion setNumeroOrden y es unico para cada cliente*/
        Pedido* pedido; /* Orden dada por un mesero, es un struct*/
        RandomGenerator randomGenerator; // Para generar su pedido y nombre random
        vector<Plato*> platosSuciosRestaurante; // Lista de platos que ha comido el cliente

    public:
        static int contadorNumOrden; // Static variable para contar el numero de ordenes entre todos los clientes
        // Constrcutor
        Cliente(vector<Plato*> pPlatosSuciosRestaurante){
            setName();
            setItem();
            setNumeroOrden();
            pedido = nullptr;
            platosSuciosRestaurante = pPlatosSuciosRestaurante;
        }

        // Setters
        void setName(){
            name = randomGenerator.getRandomName();
        }
        void setItem(){
            item = randomGenerator.getRandomFood();
        }
        void setNumeroOrden(){
            numeroOrden = new int(contadorNumOrden);
            contadorNumOrden++;
        }
        void setPedido(Pedido* pPedido){
            pedido = pPedido;
        }

        // Getters
        string getName(){
            return name;
        }
        string getItem(){
            return item;
        }
        int* getNumeroOrdenPtr(){
            return numeroOrden;
        }
        int getNumeroOrden(){
            return *numeroOrden;
        }
        Pedido* getPedido(){
            return pedido;
        }

        void comerMoncha(){
            Plato platosucio = *(pedido->plato);
            platosSuciosRestaurante.push_back(&platosucio);
            cout << "Se dejo el plato sucio en la mesa" << endl;
            cout << "El cliente " << name << " comio y se fue del restaurante" << endl;
            delete pedido;
            delete this;
        }

        string toString() {
            stringstream ss;
            ss << "Cliente { name: " << name << ", item: " << item << ", numeroOrden: " << numeroOrden << " }";
            return ss.str();
        }
};
int Cliente::contadorNumOrden = 1;
#endif // CLIENTE_H