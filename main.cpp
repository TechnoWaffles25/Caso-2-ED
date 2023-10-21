#include "clases/class_threads.h"
#include "clases/class_managerCajero.h"

using namespace std;

int main(void)
{
    Simulacion sim;

    // Managers
    ManagerCajero *managerCajero = new ManagerCajero();
    ManagerChef *managerChef = new ManagerChef();
    

    queue *fila_exterior = new queue(); // Cola donde llegan primeramente los clientes, pueden entrar al restaurante o salir si esta muy lento
    queue *pedidosPendientes = new queue(); // Cola donde se van los pedidos apuntados por los cajeros
    queue *pedidosListos = new queue(); // Cola donde van los pedidos terminados por los cocineros y seran recogidos por los meseros

    stack *platosLimpios = new stack(); // Accede a los platos que estan lavados
    stack *platosSucios = new stack(); // Accede a los platos que estan sucios

    threads thread(managerCajero, managerChef, fila_exterior, pedidosPendientes, pedidosListos, platosLimpios);
    cout << "---------------------------------------------------------" << endl;

    // Creamos los platos limpios
    for (int i = 0; i < *sim.getPlatos(); i++) {
        Plato *pPlato = new Plato("Plato" + to_string(i));
        platosLimpios->push(pPlato);
        cout << "\nSe ha creado un plato " << endl;
    }

    // Add cajeros al manager de cajeros
    for (int i = 0; i < *sim.getCajeros(); i++) {
        Cajero* pCajero = new Cajero("Cajero" + to_string(i), pedidosPendientes);
        managerCajero->addCajero(pCajero);
        vector<Cajero*> kk = managerCajero->getCajeros();
        cout << "\nSe ha creado un cajero llamado " << pCajero->getName() << endl;

    }
    // Add chefs al manager de chefs
    for (int i = 0; i < *sim.getCocineros(); i++) {
        Chef* pChef = new Chef("Chef" + to_string(i), pedidosPendientes, pedidosListos, platosLimpios);
        managerChef->addChef(pChef);
        vector<Chef*> kk = managerChef->getChef();
        cout << "\nSe ha creado un chef llamado " << pChef->getName() << endl;
    }

    cout << "---------------------------------------------------------" << endl;
    // Wait for both threads to finish
    std::thread llegadaClientesThread(&threads::llegadaClientes, &thread);
    std::thread threadCargarClientesThread(&threads::cargarClientes, &thread);
    std::thread threadCocinar(&threads::cocinarPedidos, &thread);

    llegadaClientesThread.detach();
    threadCargarClientesThread.join();
    threadCocinar.join();
    

}