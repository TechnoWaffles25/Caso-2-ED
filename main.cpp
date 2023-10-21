#include "clases/class_threads.h"
#include "clases/class_managerCajero.h"

using namespace std;

int main(void)
{
    Simulacion sim;

    // Managers
    ManagerCajero *managerCajero = new ManagerCajero();
    

    queue *fila_exterior = new queue(); // Cola donde llegan primeramente los clientes, pueden entrar al restaurante o salir si esta muy lento
    queue *pedidosPendientes = new queue(); // Cola donde se van los pedidos apuntados por los cajeros
    queue *pedidosListos = new queue(); // Cola donde van los pedidos terminados por los cocineros y seran recogidos por los meseros

    threads thread(managerCajero, fila_exterior);
    cout << "---------------------------------------------------------" << endl;

    // Add Cajero objects to the CajeroManager
    for (int i = 0; i < *sim.getCajeros(); i++) {
        Cajero* pCajero = new Cajero("Cajero" + to_string(i), pedidosPendientes);
        managerCajero->addCajero(pCajero);
        vector<Cajero*> kk = managerCajero->getCajeros();
        cout << "\nSe ha creado un cajero llamado " << pCajero->getName() << endl;

    }
    for (Cajero* cajero : managerCajero->getCajeros()){
        cout << "Existe cajero: " << cajero->getName() << endl;
    }

    cout << "---------------------------------------------------------" << endl;
    // Wait for both threads to finish
    std::thread llegadaClientesThread(&threads::llegadaClientes, &thread);
    std::thread threadCargarClientesThread(&threads::cargarClientes, &thread);

    llegadaClientesThread.detach();
    threadCargarClientesThread.join();
}