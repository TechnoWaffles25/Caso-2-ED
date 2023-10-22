    #ifndef CAJERO_H
    #define CAJERO_H

    #include "struct_pedido.h"
    #include "class_cliente.h"
    //#include "class_chef.h"
    #include "struct_pedido.h"
    #include "listas/queue.h"
    #include "listas/stack.h"
    #include "listas/lista.h"
    #include <string>
    #include <list>

    class Cajero
    {
        private:
            string name; /* Nombre sacado de la lista json */
            RandomGenerator randomGenerator;
            Cliente* clienteActual; // Puntero al cliente que se esta atendiendo en este momento
            queue* pedidosPendientes; // Cola donde se van los pedidos apuntados por los cajeros
            vector<Cliente*> restaurante;

        public:
            static int contadorPedidos; // Static variable para contar el numero de ordenes entre todos los clientes    
            
            Cajero(string name, queue* pPedidosPendientes, vector<Cliente*>  pRestaurante){
                setName(name);
                pedidosPendientes = pPedidosPendientes;
                restaurante = pRestaurante;
                clienteActual = nullptr;
            }

            string getName(){
                return name;
            }
            void setName(string pName){
                name = pName;
            }
            void setClienteActual(Cliente* cliente){
                clienteActual = cliente;
            }
            Cliente* getClienteActual(){
                return clienteActual;
            }

            Pedido* apuntarOrden(){
                Pedido* pedido = new Pedido();
                pedido->item = new string(clienteActual->getItem());
                pedido->num_orden = new int(contadorPedidos);
                pedido->listo = new bool(false);
                contadorPedidos++;
                return pedido;
            }

            void comunicarOrden(Pedido* pedido){
                pedidosPendientes->enqueue(pedido);
                cout << "\nCantidad de pedidos pendientes: " << pedidosPendientes << endl;
                cout << "\nEl cajero " << name << " le ha comunicado al chef que el cliente " << clienteActual->getName() << " ha pedido " << &pedido->item << endl;
                restaurante.push_back(clienteActual);
                cout << "\nClientes en el restaurante: " << restaurante.size() << endl;
                clienteActual = nullptr;
            }
    };
    int Cajero::contadorPedidos = 1;
    #endif // CAJERO_H