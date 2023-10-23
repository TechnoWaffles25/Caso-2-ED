#include <string>
#include "listas/stack.h"
#include "class_plato.h"
#include <iostream>

using namespace std;

class Lavaplatos {
private:
    string name; // Nombre del lavaplatos
    stack* platosSucios;
    stack* platosLimpios;

public:
    Lavaplatos(string name, stack* pPlatosSucios, stack* pPlatosLimpios){
        setName(name);
        platosSucios = pPlatosSucios;
        platosLimpios = pPlatosLimpios;
    }

    string getName() {
        return name;
    }
    void setName(string pName){
        name = pName;
    }

    // Agarra un plato de la pila de platos sucios, lo limpia y coloca el plato en la pila de platos limpios
    void limpiarPlato() {
        if (!platosSucios->isEmpty()) {
            void* platoVoid = platosSucios->pop();
            Plato* platoSucio = static_cast<Plato*>(platoVoid);
            // Simular el proceso de lavado
            cout << "LVPTS - El lavaplatos " << name << " está lavando el plato " << platoSucio->getName() << std::endl;
            // Cambiar el estado del plato a limpio
            platoSucio->cambiarLimpio();
            // Colocar el plato limpio en la pila de platos limpios
            platosLimpios->push(platoSucio);
            cout << "LVPTS - El plato " << platoSucio->getName() << " está limpio" << std::endl;
        }
    }

    // Agregar un plato sucio a la pila de platos sucios
    void agregarPlatoSucio(Plato* plato) {
        platosSucios->push(plato);
    }

    /*// Obtener un plato limpio de la pila de platos limpios
    Plato* obtenerPlatoLimpio() {
        if (!platosLimpios->isEmpty()) {
            return platosLimpios->pop();
        }
        return nullptr; // La pila de platos limpios está vacía
    }*/
};