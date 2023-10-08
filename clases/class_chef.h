#include "struct_pedido.h"
#include "class_cliente.h"
#include "class_plato.h"
#include "listas/stack.h"
#include "listas/queue.h"
#include <string>

class Chef
{
    private:
        std::string name; /* Nombre sacado de la lista json */
        Pedido orden; /* Orden dada por un mesero, es un struct*/
        Plato plato; /* Aca se sabe si el cocinero tiene o no un plato ya agarrado */
    public:
        Chef(){
            // Constructor
        }
        void getChef(){
            // Accesa el nombre del chef y la orden que esta cocinando
        }
        Plato agarrarPlato(stack platosLavados){
            // Agarra un plato de la pila de platos
        }
        void quitarPlato(Plato plato){
            // Le quita el plato al preparar la comida
        }
        Pedido cocinarPedido(Pedido pedido, Plato plato){
            // Si tiene un plato y una orden alista un pedido en un rango de tiempo
        }
        Pedido alistarPedido(Pedido pedido, queue pedidosListos){
            /* Al terminar el pedido lo alista para ser llevado por un mesero a una mesa, transforma
            la condicion bool listo del struct pedido a true para que se comido por el cliente*/
        }
};