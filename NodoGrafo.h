#ifndef _NODOGRAFO_
#define _NODOGRAFO_ 1

#include "Arco.h"
#include "INodo.h"
#include <vector>

using namespace std;

class NodoGrafo {
    private:
        INodo *dato; // Nodo con la informacion
        vector<Arco*>* listaArcos; // Esta es la lista de arcos que se asocian con ese nodo OJO CON LOS POINTERS
        bool visitado;
        bool procesado;

    public:
        NodoGrafo(INodo* pDato){
            this->dato = pDato;
            this->listaArcos = new vector<Arco*>();
            this->visitado = false;
            this->procesado = false;
        }

        NodoGrafo(){
            this->listaArcos = new vector<Arco*>();
        }

        void setInfo(INodo* pDato){
            this->dato = pDato;
        }

        INodo* getInfo(){
            return this->dato;
        }

        void AddArco(Arco* pArco){
            this->listaArcos->push_back(pArco);
        }
        
        vector<Arco*>* getArcos(){
            return this->listaArcos;
        }
        void setVisitado(bool pVisitado){
            this->visitado = pVisitado;
        }
        bool getVisitado(){
            return this->visitado;
        }
        void setProcesado(bool pProcesado){
            this->procesado = pProcesado;
        }
        bool getProcesado(){
            return this->procesado;
        }
        
};
#endif