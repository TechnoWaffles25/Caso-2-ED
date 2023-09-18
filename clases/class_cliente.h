#include <string>
class Cliente
{
    private:
        std::string name; /* Nombre sacado de la lista json */
        std::string item; /* obtenido por la funcion decidirPedido */
    public:
        Cliente(){
            // Constructor
        }
        void getCliente(){
            // Accesa el nombre y la orden del cliente
        }
        void moverCliente(){
            /* Dependiendo de donde este el cliente (cola, caja, restaurante) se mueve al la
            siguiente estacion (cola->caja, caja->restaurante, restaurante->afuera) */
        }
        void comerMoncha(){
            /* El cliente come su comida en un rango de tiempo, generando un plato sucio 
            y eliminando el struct pedido*/
        }
        void decidirPedido(){
            /* De manera al azar se escoge un item de la lista "productos" del json */
        }
};