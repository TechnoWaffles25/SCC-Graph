#ifndef _FOTO_
#define _FOTO_ 1

#include <iostream>
#include "INodo.h"
#include <string>

using namespace std;

class Gear : public INodo  {
    public:
        Gear(){
            this->setId(rand()*999);
        }
        
};
#endif