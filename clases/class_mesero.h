#include "struct_pedido.h"
#include "class_cliente.h"
#include "class_chef.h"
#include "class_plato.h"
#include "listas/queue.h"
#include <string>
#include <queue>


class Mesero {
private:
    std::string name; // Nombre del mesero
    Pedido orden;     // Item deseado por el cliente, más el número de orden dado en la caja

public:
    Mesero(const std::string& pName) : name(pName) {
        // Constructor
    }

    void getMesero() {
        // Accede al nombre del mesero y su número de orden actual si tiene
    }

    void servirOrden(Cliente* cliente, queue<Pedido>& ordenesListas) {
        // Recoge la orden preparada por el chef y la lleva a la mesa
        if (cliente && !ordenesListas.isEmpty()) {
            Pedido* pedido = ordenesListas.dequeue();
            // Realiza la lógica para servir la orden al cliente
        }
    }

    // Otras funciones y métodos, si es necesario

    void limpiarMesa(stack<Plato>& platosSucios) {
        // Limpia la mesa y lleva el plato sucio dejado por la persona a la pila de platos sucios
        if (!platosSucios.isEmpty()) {
            Plato plato = platosSucios.pop();
            // Realiza la lógica para limpiar la mesa y manejar platos sucios
        }
    }
};