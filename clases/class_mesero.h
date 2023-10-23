#include "struct_pedido.h"
#include "class_cliente.h"
#include "class_chef.h"
#include "class_plato.h"
#include "listas/queue.h"
#include "listas/lista.h"
#include "listas/stack.h"
#include <string>

using namespace std;

class Mesero {
private:
    string name; // Nombre del mesero
    Pedido* pedido;   // Item deseado por el cliente, más el número de orden dado en la caja
    queue* pedidosListos; // Cola donde van los pedidos terminados por los cocineros y serán recogidos por los meseros
    stack* platosSucios;
    vector<Cliente*>  restaurante; 
public:
    Mesero(string pName, queue* pPedidosListos, vector<Cliente*>  pRestaurante, stack* pPlatosSucios){
        name = pName;
        pedidosListos = pPedidosListos;
        restaurante = pRestaurante;
    }

    string getName(){
        return name;
    }
    void servirOrden() {
        // Recoge la orden preparada por el chef y la lleva a la mesa
        cout << "MESERO - El mesero " << name << " esta recogiendo un pedido" << endl;
        pedido = static_cast<Pedido*>(pedidosListos->dequeue());
        cout << "MESERO - El mesero " << name << " agarro el pedido " << *pedido->num_orden << endl;
        cout << "RESTAURANTE SIZE " << restaurante.size() << endl;
        for (int i = 0; i < restaurante.size(); i++) {
            Cliente* cliente = restaurante.at(i);
            cout << "NUMERO ORDEN CLIENTE: " << *cliente->getNumeroOrdenPtr() << endl;
            if (*cliente->getNumeroOrdenPtr() == *pedido->num_orden) {
                cliente->setPedido(pedido);
                cout << "MESERO - El mesero " << name << " le ha servido el pedido " << pedido << " al cliente " << cliente->getName() << endl;
                break;
            }
        }
    }

    /*void limpiarMesa() {
        // Limpia la mesa y lleva el plato sucio dejado por la persona a la pila de platos sucios
        for (Plato* plato : platosSucios) {
                platosSucios->push(plato);
                cout << "MESERO - El mesero " << name << " recogio el plato sucio" << endl;
                }
    }*/
};