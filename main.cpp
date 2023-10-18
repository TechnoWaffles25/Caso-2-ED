#include "clases/class_threads.h"

using namespace std;



/*void operationCajero()
{   
    using namespace std::literals::chrono_literals;

    vector<Cajero*> cajeros;
    int* numCajeros = simulacion.getCajeros();

    int* atencionCajeroMin = simulacion.getTiempoAtencionSegMin();
    int* atencionCajerMax = simulacion.getTiempoAtencionSegMax();

    for (int i = 0; i < *numCajeros; i++)
    {
        string cajeroName = "Cajero " + to_string(i + 1);
        Cajero* newCajero = new Cajero(cajeroName);
        cajeros.push_back(newCajero);
        cout << "\nSe ha creado un cajero llamado " << newCajero->getName() << endl;
    }

    while (!fila_exterior.isEmpty()) {
    for (int i = 0; i < *numCajeros && !fila_exterior.isEmpty(); i++) {
        cout << "\nCajero " << i << " está sirviendo." << endl;
        void* ptr = fila_exterior.dequeue();
        Cliente* cliente = static_cast<Cliente*>(ptr);
        cajeros[i]->setClienteActual(cliente);
        cajeros[i]->atenderCliente();
        int serveTime = 5;
        this_thread::sleep_for(serveTime * std::chrono::seconds(1));
        Pedido* pedido = cajeros[i]->apuntarOrden();
        cajeros[i]->comunicarOrden(pedido);
    }
}
cout << "Todos los clientes fueron servidos" << endl;
}*/


int main(void)
{
    // Create a thread for the llegadaClientes() function
    

    // Create a thread for the operationCajero() function
    //thread cajeroThread(operationCajero);

    threads thread;
    // Wait for both threads to finish
    thread.llegadaClientes();
    //cajeroThread.join();
}