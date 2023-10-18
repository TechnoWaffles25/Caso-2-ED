#ifndef MANAGER_H
#define MANAGER_H

#include "class_cajero.h"
#include "class_chef.h"
#include <vector>

class CajeroManager {
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

class ChefManager {
    private:
        vector<Chef*> chefs;

    public:
        void addChef(Chef* pChef){
            chefs.push_back(pChef);
        }	
        vector<Chef*> getChefs() const{
            return chefs;
        }
};

class Manager {
    private:
        CajeroManager cajeroManager;
        ChefManager chefManager;

    public:
        void addCajero(Cajero* pCajero) {
            cajeroManager.addCajero(pCajero);
        }
        void addChef(Chef* pChef) {
            chefManager.addChef(pChef);
        }
        vector<Cajero*> getCajeros() const{
            return cajeroManager.getCajeros();
        }
        vector<Chef*> getChefs() const{
            return chefManager.getChefs();
        }
};

#endif // MANAGER_H