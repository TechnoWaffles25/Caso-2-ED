#include <struct_pedido.h>
#include <class_cliente.h>
#include <class_chef.h>
#include <class_plato.h>
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
        void apuntarOrden(Cliente cliente_orden){
            // Atiende a un cliente en la caja SOLO si hay espacio en el vector restaurante
            // Crea el struct y le pone la string item, int num_orden y el bool listo = False
        }
        void comunicarOrden(Pedido pedido, Chef chef){
            // Le lleva la informacion de la orden al chef para que la cocine
        }
        void servirOrden(Cliente numero_cliente, Pedido pedido){
            // Recoje la orden preparada por el chef y la lleva a la mesa
        }
        Plato limpiarMesa(){
            // Limpia la mesa y lleva el plato sucio dejado por la persona a la pila de platos sucios
        }
};