#ifndef MANAGERCAJERO_H
#define MANAGERCAJERO_H

#include <vector>
#include "class_cajero.h"

class ManagerCajero {
    private:
        vector<Cajero*> cajeros;
    public:
        void addCajero(Cajero* pCajero){
            cajeros.push_back(pCajero);
        }
        
        vector<Cajero*> getCajeros() const{
            return cajeros;
        }
};
#endif  // MANAGERCAJERO_H