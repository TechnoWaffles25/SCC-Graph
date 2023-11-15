#ifndef _GRAFO_
#define _GRAFO_ 1

#include <vector>
#include <map>
#include <queue>
#include <iostream>
#include <stack>
#include "NodoGrafo.h"
#include "Arco.h"
#include "INodo.h"

using namespace std;

class Grafo {
    private:
        vector<NodoGrafo*>* listaNodos;
        map<int, NodoGrafo*>* hashNodos;
        bool esDirigido;

        void resetNodes(){
            for (vector<NodoGrafo*>::iterator it = this->listaNodos->begin(); it != this->listaNodos->end(); ++it){
                NodoGrafo* actual = *it;
                actual->setVisitado(false);
                actual->setProcesado(false);
            }
        }

        NodoGrafo* findNotVisited(){
            NodoGrafo *result = nullptr;
            for (vector<NodoGrafo*>::iterator it = listaNodos->begin(); it != listaNodos->end(); ++it){
                NodoGrafo* actual = *it;
                if (actual->getVisitado() == false){
                    result = actual;
                    break;
                }
            }
            return result;
        }

    public:
        Grafo(bool dirigido){
            this->esDirigido = dirigido;
            this->listaNodos = new vector<NodoGrafo*>();
            this->hashNodos = new map<int, NodoGrafo*>();
        }
        
        int getSize(){
            return this->listaNodos->size();
        }
        vector<NodoGrafo*>* getListNodos(){
            return this->listaNodos;
        }
        map<int, NodoGrafo*>* getHashNodos(){
            return this->hashNodos;
        }
        
        NodoGrafo* addNode(INodo* pNodo){
            NodoGrafo* newNode = new NodoGrafo(pNodo);
            this->listaNodos->push_back(newNode);
            hashNodos->insert(pair<int,NodoGrafo*>(pNodo->getId(), newNode));
            return newNode;
        }

        void addArc(NodoGrafo *pOrigen, NodoGrafo *pDestino){
            this->addArcWeight(pOrigen, pDestino, 0);
        }

        void addArcWeight(NodoGrafo *pOrigen, NodoGrafo *pDestino, int pPeso){
            Arco* newArc = new Arco(pOrigen, pDestino, pPeso);
            pOrigen->AddArco(newArc);
            if (!this->esDirigido){
                Arco* newArc2 = new Arco(pDestino, pOrigen, pPeso);
                pDestino->AddArco(newArc2);
            }
        }

        void printCounters(){
            for (vector<NodoGrafo*>::iterator it = listaNodos->begin(); it != listaNodos->end(); ++it){
                NodoGrafo* actual = *it;
                cout << "Nodo: " << actual->getInfo()->getId() << " Tiene: " << actual->getArcos()->size() << " arcos"<< endl;
            }
        }

        Grafo* reverse(){
            Grafo* reversedGraph = new Grafo(this->esDirigido);

            // Copy all nodes to the reversed graph
            for (auto& pair : *this->hashNodos) {
                reversedGraph->addNode(pair.second->getInfo());
            }

            // Reverse all arcs
            for (auto& pair : *this->hashNodos) {
                NodoGrafo* node = pair.second;
                for (Arco* arco : *node->getArcos()) {
                    NodoGrafo* destino = static_cast<NodoGrafo*>(arco->getDestino());
                    reversedGraph->addArc(reversedGraph->hashNodos->at(destino->getInfo()->getId()), reversedGraph->hashNodos->at(node->getInfo()->getId()));
                }
            }
            return reversedGraph;
        }

        vector<INodo*> deepPath(INodo* pOrigen){
            // Crear un vector para almacenar el camino, crear una pila y agregar el nodo de origen a la pila
            vector<INodo*> path;
            stack<NodoGrafo*> stack;
            NodoGrafo* origen = hashNodos->at(pOrigen->getId());
            stack.push(origen);

            // Mientras la pila no esté vacía
            while (!stack.empty()){
                // Tomar el nodo superior de la pila
                NodoGrafo* nodo = stack.top();
                stack.pop();

                // Si el nodo no ha sido visitado
                if (!nodo->getVisitado()){
                    // Marcar el nodo como visitado
                    nodo->setVisitado(true);

                    // Agregar el nodo al camino y lo marca como procesado
                    path.push_back(nodo->getInfo());
                    nodo->setProcesado(true);

                    // Agregar todos los nodos adyacentes no visitados a la pila
                    vector<Arco*> *arcos = nodo->getArcos();
                    for (vector<Arco*>::iterator it = arcos->begin(); it != arcos->end(); ++it){
                        Arco* arco = *it;
                        NodoGrafo* adyacente = static_cast<NodoGrafo*>(arco->getDestino());
                        if (!adyacente->getVisitado() && !adyacente->getProcesado()){
                            stack.push(adyacente);
                        }
                    }
                }
            }

            // Devolver el camino y agregar el nodo de origen a la pila de tiempos de finalización
            return path;
        }

        vector<INodo*> dpForSCC(INodo* pOrigen, vector<NodoGrafo*>& finishTimes){
            // Create a vector to store the path, create a stack and add the origin node to the stack
            vector<INodo*> path;
            stack<NodoGrafo*> stack;
            NodoGrafo* origen = hashNodos->at(pOrigen->getId());
            stack.push(origen);

            // While the stack is not empty
            while (!stack.empty()){
                // Take the top node from the stack
                NodoGrafo* nodo = stack.top();
                stack.pop();

                // If the node has not been visited
                if (!nodo->getVisitado()){
                    // Mark the node as visited
                    nodo->setVisitado(true);

                    // Add the node to the path
                    path.push_back(nodo->getInfo());

                    // Add all unvisited adjacent nodes to the stack
                    vector<Arco*> *arcos = nodo->getArcos();
                    for (vector<Arco*>::iterator it = arcos->begin(); it != arcos->end(); ++it){
                        Arco* arco = *it;
                        NodoGrafo* adyacente = static_cast<NodoGrafo*>(arco->getDestino());
                        if (!adyacente->getVisitado()){
                            stack.push(adyacente);
                        }
                    }
                }
                // Add the node to the finish times vector
                finishTimes.push_back(nodo);
            }
            // Return the path
            return path;
        }

        vector<vector<INodo*>> StronglyConnectedComponents() {
            // Step 1: Perform DFS to compute finish times
            vector<NodoGrafo*> finishTimes;
            for (auto& pair : *hashNodos) {
                NodoGrafo* node = pair.second;
                if (!node->getVisitado()) {
                    dpForSCC(node->getInfo(), finishTimes);
                }
            }

            // Reset visited status of all nodes
            resetNodes();

            // Step 2: Reverse the graph
            Grafo* reversedGraph = reverse();

            // Step 3: Perform DFS on reversed graph in order of decreasing finish time
            vector<vector<INodo*>> stronglyConnectedComponents;
            for (int i = finishTimes.size() - 1; i >= 0; --i) {
                NodoGrafo* node = finishTimes[i];
                if (!reversedGraph->hashNodos->at(node->getInfo()->getId())->getVisitado()) {
                    vector<NodoGrafo*> sccFinishTimes;
                    vector<INodo*> scc = reversedGraph->dpForSCC(node->getInfo(), sccFinishTimes);
                    stronglyConnectedComponents.push_back(scc);
                }
            }

            delete reversedGraph;
            return stronglyConnectedComponents;
        }

        /*vector<INodo*> broadPath(INodo* pOrigen){
            vector<INodo*> result;
            queue<NodoGrafo*> nodosProcesados;
            int contador = 0;

            resetNodes();

            NodoGrafo *origin = this->getNodo(pOrigen->getId());
            origin->setVisitado(true);
            nodosProcesados.push(origin);

            do
            {
                while (!nodosProcesados.empty()){
                    NodoGrafo* actual = nodosProcesados.front();
                    nodosProcesados.pop();
                    result.push_back(actual->getInfo());
                    vector<Arco*>* adyacentes = actual->getArcos();

                    for (int idxArcos = 0; idxArcos < adyacentes->size(); ++idxArcos){
                        Arco *arco = adyacentes->at(idxArcos);
                        NodoGrafo *adyacente = (NodoGrafo*)arco->getDestino();
                        if(adyacente->getProcesado() == false){
                            adyacente->setProcesado(true);
                            nodosProcesados.push(adyacente);
                        }
                    }
                }
                if (visitados < this->getSize()){
                    puntoPartida = this->findNotVisited();
                    puntoPartida->visitado = true;
                    nodosProcesados.push(puntoPartida);
                }
            } while (visitados < this->getSize());
            return result;
        }
        
        vector<INodo> path(INodo* pOrigen, INodo *pDestino){
            vector<INodo> result;
            NodoGrafo* origen = hashNodos[pOrigen->getId()];
            NodoGrafo* destino = hashNodos[pDestino->getId()];
            queue<NodoGrafo*> cola;
            cola.push(origen);
            origen->visitado = true;
            while (!cola.empty()){
                NodoGrafo* actual = cola.front();
                cola.pop();
                if (actual == destino){
                    result.push_back(actual->getInfo());
                    break;
                }
                for (vector<Arco*>::iterator it = actual->getArcs()->begin(); it != actual->getArcs()->end(); ++it){
                    Arco* actualArc = *it;
                    NodoGrafo* nodoDestino = actualArc->getDestino();
                    if (!nodoDestino->visitado){
                        nodoDestino->visitado = true;
                        cola.push(nodoDestino);
                    }
                }
            }
            return result;
        }*/
};
#endif