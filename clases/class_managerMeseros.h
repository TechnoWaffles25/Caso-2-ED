#ifndef MANAGERMESEROS_H
#define MANAGERMESEROS_H

#include <vector>
#include "class_mesero.h"

class ManagerMesero {
    private:
        vector<Mesero*> meseros;
    public:
        void addMesero(Mesero* pMesero){
            meseros.push_back(pMesero);
        }
        
        vector<Mesero*> getMesero() const{
            return meseros;
        }
};
#endif  // MANAGERCAJERO_H