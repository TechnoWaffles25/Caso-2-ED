#include <struct_pedido.h>
#include <class_cliente.h>
#include <class_chef.h>
#include <class_plato.h>
#include <queue.h>
#include <string>

class Mesero
{
    private:
        std::string name; /* Nombre sacado de la lista json */
        Pedido orden; /* Item deseado por el cliente, mas el numero de orden dado en la caja */
    public:
        Mesero(){
            // Constructor
        }
        void getMesero(){
            // Accesa el nombre del mesero y su numero de orden actual si tiene
        }
        void servirOrden(Cliente numero_cliente, queue ordenesListas){
            // Recoje la orden preparada por el chef y la lleva a la mesa
        }
        Plato limpiarMesa(){
            // Limpia la mesa y lleva el plato sucio dejado por la persona a la pila de platos sucios
        }
};