#include <struct_pedido.h>
#include <class_cliente.h>
#include <class_chef.h>
#include <struct_pedido.h>
#include <listas/queue.h>
#include <string>

class Cajero
{
    private:
        std::string name; /* Nombre sacado de la lista json */

    public:
        Cajero(){
            // Constructor
        }
        void getCajero(){
            // Accesa el nombre del cajero
        }
        Pedido apuntarOrden(Cliente cliente_orden){
            // Atiende a un cliente en la caja SOLO si hay espacio en el vector restaurante
            // Crea el struct y le pone la string item, int num_orden y el bool listo = False
            // El cliente luego pasa al area comun
        }
        void comunicarOrden(Pedido pedido, queue pedidosPendientes){
            // Coloca la orden en la cola de ordenes para que un chef la reciba y la cocine
        }
};