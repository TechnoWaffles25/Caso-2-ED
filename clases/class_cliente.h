#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <sstream>
#include "class_randomgenerator.h"
using namespace std;
class Cliente
{
    private:
        string name; /* Nombre sacado de la lista json */
        string item; /* obtenido por la funcion decidirPedido */ // PRIMERAMENTE ES NULL
        int numeroOrden; /* Se settea con la funcion setNumeroOrden y es unico para cada cliente*/
        RandomGenerator randomGenerator; // Para generar su pedido y nombre random
    public:
        static int contadorPedidos; // Static variable para contar el numero de ordenes entre todos los clientes
        
        // Constrcutor
        Cliente(){
            setName();
            setItem();
            setNumeroOrden();
        }

        // Setters
        void setName(){
            name = randomGenerator.getRandomName();
        }
        void setItem(){
            item = randomGenerator.getRandomFood();
        }
        void setNumeroOrden(){
            numeroOrden = contadorPedidos;
            contadorPedidos++;
        }

        // Getters
        string getName(){
            return name;
        }
        string getItem(){
            return item;
        }
        int getNumeroOrden(){
            return numeroOrden;
        }

        // Funciones del simulador
        void moverCliente(){
            /* Dependiendo de donde este el cliente (cola, caja, restaurante) se mueve al la
            siguiente estacion (cola->caja, caja->restaurante, restaurante->afuera) */
        }
        void comerMoncha(){
            /* El cliente come su comida en un rango de tiempo, generando un plato sucio 
            y eliminando el struct pedido*/
        }

        string toString() {
            stringstream ss;
            ss << "Cliente { name: " << name << ", item: " << item << ", numeroOrden: " << numeroOrden << " }";
            return ss.str();
        }
};
#endif // CLIENTE_H