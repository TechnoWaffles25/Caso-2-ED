#include <string>
#include "listas/stack.h"
#include "class_plato.h"
#include <iostream>

class Lavaplatos
{
private:
    std::string name; /* Nombre sacado de la lista json */
    stack platosSucios;
    stack platosLimpios;

public:
    Lavaplatos(std::string pName) : name(pName) {}

    std::string getName() {
        return name;
    }

    // Agarra un plato de la pila de platos sucios, lo limpia y coloca el plato en la pila de platos limpios
    void limpiarPlato() {
        if (!platosSucios.isEmpty()) {
            Plato* platoSucio = static_cast<Plato*>(platosSucios.pop());
            // Simular el proceso de lavado
            std::cout << "El lavaplatos " << name << " está lavando el plato " << platoSucio->getName() << std::endl;
            // Cambiar el estado del plato a limpio
            platoSucio->cambiarLimpio();
            // Colocar el plato limpio en la pila de platos limpios
            platosLimpios.push(platoSucio);
            std::cout << "El plato " << platoSucio->getName() << " está limpio" << std::endl;
        }
    }

    // Agregar un plato sucio a la pila de platos sucios
    void agregarPlatoSucio(Plato* plato) {
        platosSucios.push(plato);
    }

    // Obtener un plato limpio de la pila de platos limpios
    Plato* obtenerPlatoLimpio() {
        if (!platosLimpios.isEmpty()) {
            return static_cast<Plato*>(platosLimpios.pop());
        }
        return nullptr; // La pila de platos limpios está vacía
    }
};