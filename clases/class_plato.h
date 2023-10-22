#ifndef CLASS_PLATO_H
#define CLASS_PLATO_H

#include <string>
using namespace std;

class Plato
{
private:
    bool limpio; /* True o False */
    string name;

public:
    Plato(string pName) : limpio(true), name(pName) {}

    bool getPlato() {
        return limpio;
    }

    void cambiarLimpio() {
        limpio = !limpio;
    }

    string getName() {
        return name;
    }
};
#endif // CLASS_PLATO_H