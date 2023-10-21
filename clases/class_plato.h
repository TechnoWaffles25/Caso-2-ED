#ifndef CLASS_PLATO_H
#define CLASS_PLATO_H

#include <string>
using namespace std;

class Plato
{
    private:
        bool limpio; /* True o False */
        string Name;
    public:
        Plato(string pName){
            limpio = true;
            Name = pName;
        }
        bool getPlato(){
            return limpio;
        }
        void cambiarLimpio(){
            limpio = !limpio;
        }
};
#endif // CLASS_PLATO_H