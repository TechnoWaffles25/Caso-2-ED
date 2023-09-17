#include <string>

struct Pedido{
        std::string item;// Lo que haya pedido el cliente
        int num_orden; // Contador
        bool listo; // Para saber si el pedido ya fue preparado por el chef o no
    };