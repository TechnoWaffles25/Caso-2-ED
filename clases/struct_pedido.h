#ifndef STRUCT_PEDIDO_H
#define STRUCT_PEDIDO_H

#include "class_plato.h"
#include <string>

struct Pedido{
        std::string* item;// Lo que haya pedido el cliente
        Plato* plato; // El plato sobre el que va montado el pedido
        int* num_orden; // Contador
        bool* listo; // Para saber si el pedido ya fue preparado por el chef o no
    };

#endif // STRUCT_PEDIDO_H