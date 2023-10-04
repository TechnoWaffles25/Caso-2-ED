#ifndef _QUEUE_
#define _QUEUE_ 0

#include "lista.h"
#include <class_cliente.h>

struct queue
{
    struct listadoble stackList;

    bool isEmpty()
    {
        return stackList.isEmpty();
    };

    void enqueue(void *pElement)
    {
        stackList.addToEnd(pElement);
    };

    void *dequeue()
    {
        return stackList.removeFirst();
    }
};
queue fila_exterior; // Cola donde llegan primeramente los clientes, pueden entrar al restaurante o salir si esta muy lento
queue ordenesPendientes; // Cola donde se van los pedidos apuntados por los cajeros
queue pedidosListos; // Cola donde van los pedidos terminados por los cocineros y seran recogidos por los meseros
#endif