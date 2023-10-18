#ifndef CAJERO_H
#define CAJERO_H

#include "struct_pedido.h"
#include "class_cliente.h"
//#include "class_chef.h"
#include "struct_pedido.h"
#include "listas/queue.h"
#include "listas/stack.h"
#include <string>

class Cajero
{
    private:
        string name; /* Nombre sacado de la lista json */
        RandomGenerator randomGenerator;
        stack clienteCajero; // Stack para almacenar el cliente que esta siendo atendido
        Cliente* clienteActual; // Puntero al cliente que se esta atendiendo en este momento
    public:
        static int contadorPedidos; // Static variable para contar el numero de ordenes entre todos los clientes    
        Cajero(string name){
            setName(name);
            clienteActual = nullptr;
        }

        string getName(){
            return name;
        }
        void setName(string pName){
            name = pName;
        }
        void setClienteActual(Cliente* cliente){
            clienteActual = cliente;
        }
        Cliente* getClienteActual(){
            return clienteActual;
        }

        Pedido* apuntarOrden(){
            Pedido* pedido = new Pedido();
            pedido->item = new string(clienteActual->getItem());
            pedido->num_orden = new int(contadorPedidos);
            pedido->listo = new bool(false);
            contadorPedidos++;
            return pedido;
        }

        void atenderCliente(){
            while (!fila_exterior.isEmpty()) {
            clienteActual = (Cliente*)fila_exterior.dequeue();
            clienteCajero.push(clienteActual);
            cout << "\nEl cajero " << name << " está atendiendo al cliente " << clienteActual->getName() << endl;
            Pedido* pedido = apuntarOrden();
            comunicarOrden(pedido);
    }
        }
        void comunicarOrden(Pedido* pedido){
            pedidosPendientes.enqueue(&pedido);
            clienteCajero.pop();
            cout << "\nEl cajero " << name << " le ha comunicado al chef que el cliente " << clienteActual->getName() << " ha pedido " << &pedido->item << endl;
        }
};
int Cajero::contadorPedidos = 1;
#endif // CAJERO_H