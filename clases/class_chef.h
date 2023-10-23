#ifndef CLASS_CHEF_H
#define CLASS_CHEF_H

#include "struct_pedido.h"
#include "class_cliente.h"
#include "class_plato.h"
#include "listas/stack.h"
#include "listas/queue.h"
#include <string>

using namespace std;
class Chef
{
    private:
        string name; /* Nombre sacado de la lista json */
        Pedido* pedido; /* Orden dada por un mesero, es un struct*/
        Plato* plato = nullptr; /* Aca se sabe si el cocinero tiene o no un plato ya agarrado */
        
        queue* pedidosPendientes; // Cola donde se van los pedidos apuntados por los cajeros
        queue* pedidosListos; // Cola donde van los pedidos terminados por los cocineros y seran recogidos por los meseros
        stack* platosLavados; // Accede a los platos que estan lavados
    public:
        Chef(string name, queue* pPedidosPendientes, queue* pPedidosListos, stack* pPlatosLavados){
            setName(name);
            pedidosPendientes = pPedidosPendientes;
            platosLavados = pPlatosLavados;
            pedidosListos = pPedidosListos;
            pedido = nullptr;
        }
        void setName(string pName){
            name = pName;
        }
        string getName(){
            return name;
        }
        Pedido* getPedido(){
            return pedido;
        }
        void setPedido(){
            pedido = static_cast<Pedido*>(pedidosPendientes->dequeue());
            cout << "\nCHEF - El chef agarro el pedido " << pedido << endl;
        }
        void setPlato(){
            plato = static_cast<Plato*>(platosLavados->pop());
            cout << "\nCHEF - El chef agarro el plato " << endl;
        }
        Plato* getPlato(){
            return plato;
        }
        void quitarPlato(Plato pPlato){
            plato = nullptr;
        }
        void cocinarPedido(){
            // Cambiamos el estado del plato a sucio y la comida ahora esta cocinada
            cout << "\nCHEF - El chef" << getName() << "esta cocinando el pedido" << endl;
            plato->cambiarLimpio();
            pedido->listo = new bool(true);
        }
        void alistarPedido(){
            pedido->plato = plato;
            pedidosListos->enqueue(pedido);
            cout << "\nCHEF - El pedido esta listo" << endl;
            pedido = nullptr;
            plato = nullptr;
        }
};
#endif // CLASS_CHEF_H