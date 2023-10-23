#include "clases/class_threads.h"

using namespace std;

int main(void)
{
    Simulacion sim;

    // Managers
    ManagerCajero *managerCajero = new ManagerCajero();
    ManagerChef *managerChef = new ManagerChef();
    ManagerMesero *managerMesero = new ManagerMesero();
    
    queue *fila_exterior = new queue(); // Cola donde llegan primeramente los clientes, pueden entrar al restaurante o salir si esta muy lento
    queue *pedidosPendientes = new queue(); // Cola donde se van los pedidos apuntados por los cajeros
    queue *pedidosListos = new queue(); // Cola donde van los pedidos terminados por los cocineros y seran recogidos por los meseros

    stack *platosLimpios = new stack(); // Accede a los platos que estan lavados
    stack *platosSucios = new stack(); // Accede a los platos que estan sucios

    vector<Cliente*> restaurante; // Lista doblemente enlazada donde se encuentran los clientes que estan en el restaurante
    vector<Plato*> platosSuciosRestaurante; // Lista doblemente enlazada donde se encuentran los platos que estan en el restaurante
    threads thread(managerCajero, managerChef, managerMesero, fila_exterior, pedidosPendientes, 
                    pedidosListos, platosLimpios, restaurante, platosSuciosRestaurante);

    cout << "---------------------------------------------------------" << endl;

    // Creamos los platos limpios
    for (int i = 0; i < *sim.getPlatos(); i++) {
        Plato *pPlato = new Plato("Plato" + to_string(i));
        platosLimpios->push(pPlato);
        cout << "\nSe ha creado un plato " << endl;
    }

    // Add cajeros al manager de cajeros
    for (int i = 0; i < *sim.getCajeros(); i++) {
        Cajero* pCajero = new Cajero("Cajero" + to_string(i), pedidosPendientes, restaurante);
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
    // Add meseros al manager de meseros
    for (int i = 0; i < *sim.getMeseros(); i++){
        Mesero* pMesero = new Mesero("Mesero" + to_string(i), pedidosListos, restaurante, platosSuciosRestaurante, platosSucios);
        managerMesero->addMesero(pMesero);
        vector<Mesero*> kk = managerMesero->getMesero();
        cout << "\nSe ha creado un mesero llamado " << pMesero->getName() << endl;
    }

    cout << "---------------------------------------------------------" << endl;
    // Wait for both threads to finish
    std::thread llegadaClientesThread(&threads::llegadaClientes, &thread);
    std::thread threadCargarClientesThread(&threads::cargarClientes, &thread);
    std::thread threadCocinar(&threads::cocinarPedidos, &thread);
    //std::thread threadServir(&threads::servirPedido, &thread);

    llegadaClientesThread.detach();
    threadCargarClientesThread.join();
    threadCocinar.join();
    //threadServir.join();
    
}