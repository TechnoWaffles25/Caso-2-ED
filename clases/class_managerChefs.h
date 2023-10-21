#ifndef MANAGERCHEFS_H
#define MANAGERCHEFS_H

#include <vector>
#include "class_chef.h"

class ManagerChef {
    private:
        vector<Chef*> chefs;
    public:
        void addChef(Chef* pChef){
            chefs.push_back(pChef);
        }
        
        vector<Chef*> getChef() const{
            return chefs;
        }
};
#endif  // MANAGERCAJERO_H