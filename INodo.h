#ifndef _INODO_
#define _INODO_ 1

#include <iostream>
#include <string>

using namespace std;

class INodo {
    public:
        int getId(){
            return id;
        }
        void setId(int id){
            this->id = id;
        }
        string getGear(){
            return gear;
        }
        void setGear(string gear){
            this->gear = gear;
        }
    protected:
        int id;
        string gear;
};
#endif