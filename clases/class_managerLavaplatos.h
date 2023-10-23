#ifndef MANAGERLAVAPLATOS_H
#define MANAGERLAVAPLATOS_H

#include <vector>
#include "class_lavaplatos.h"

class ManagerLavaplatos {
    private:
        vector<Lavaplatos*> lavaplatos;
    public:
        void addLavaplatos(Lavaplatos* pLavaplatos){
            lavaplatos.push_back(pLavaplatos);
        }
        
        vector<Lavaplatos*> getLavaplatos() const{
            return lavaplatos;
        }
};
#endif  // MANAGERCAJERO_H