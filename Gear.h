#ifndef _FOTO_
#define _FOTO_ 1

#include <iostream>
#include "INodo.h"

using namespace std;

class Gear : public INodo  {
    public:
        Gear(){
            this->setId(rand()*999);
        }

        string getGear(){
            return gear;
        }

        void setGear(string pGear){
            this->gear = pGear;
        }

        private:
            string gear;
};
#endif