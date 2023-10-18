#ifndef MANAGER_H
#define MANAGER_H

#include "class_cajero.h"
#include "class_chef.h"
#include "class_mesero.h"
#include "class_lavaplatos.h"

#include <string>
#include <sstream>

using namespace std;

class Manager
{
    private:
        vector<Cajero*> cajeros;
        vector<Chef*> chefs;
        vector<Mesero*> meseros;
        vector<Lavaplatos*> lavaplatos;

    public:
        vector<Cajero*> getCajeros() const {
            return cajeros;
        }

        vector<Chef*> getChefs() const {
            return chefs;
        }

        vector<Mesero*> getMeseros() const {
            return meseros;
        }

        vector<Lavaplatos*> getLavaplatos() const {
            return lavaplatos;
        }

        void addCajero(Cajero* cajero) {
            cajeros.push_back(cajero);
        }
        void addChef(Chef* chef) {
            chefs.push_back(chef);
        }
        void addMesero(Mesero* mesero) {
            meseros.push_back(mesero);
        }
        void addLavaplatos(Lavaplatos* lavaplat) {
            lavaplatos.push_back(lavaplat);
        }
};
#endif // MANAGER_H