#ifndef _INODO_
#define _INODO_ 1

class INodo {
    public:
        int getId(){
            return id;
        }
        void setId(int id){
            this->id = id;
        }
    protected:
        int id;
};
#endif