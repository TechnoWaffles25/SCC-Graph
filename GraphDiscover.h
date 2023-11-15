#ifndef _GRAPHDISCOVER_
#define _GRAPHDISCOVER_ 1

#include <iostream>
#include "INodo.h"
#include "grafo.h"

using namespace std;

struct Path
{
    INodo *origen = nullptr;
    INodo *destino = nullptr;
    int peso;

    vector<INodo*> path;
};

struct DistancePath
{
    INodo *keyNode = nullptr;
    INodo *LastNodo = nullptr;
    bool procesado = false;
    int peso = 999999999;
};

class GraphDiscover
{
public:
    // WARSHALL
    vector<Path *> *getPathsByWarshall(INodo *pOrigen, INodo *pDestino, Grafo *pGrafo)
    {
        // el método usa el algoritmo de Warshall implementado con listas de adyacencia, el cual calcula todos los caminos posibles de todos los vertices en pGrafo
        // retorna todos los Path posibles de pOrigen ha pDestino
        // paths en Path es la lista de INodos que componen un posible camino y el peso es para ese respectivo camino
    }

    // DIJKSTRA
    Path *getShorterPath(INodo *pOrigen, INodo *pDestino, Grafo *pGrafo){
        // Inicializar los vectores
        vector<DistancePath *> pendingNodesV;
        vector<DistancePath *> processedNodesF;

        // Inicializar todos los nodos con distancia infinita y no procesados
        for (auto nodo : *pGrafo->getListNodos()) {
            DistancePath *dp = new DistancePath();
            dp->keyNode = nodo->getInfo();
            dp->peso = (nodo->getInfo() == pOrigen) ? 0 : INT_MAX;
            pendingNodesV.push_back(dp);
        }

        while (!pendingNodesV.empty()) {
            // Encontrar el nodo con la distancia mínima en pendingNodesV
            auto it = min_element(pendingNodesV.begin(), pendingNodesV.end(),
                                [](const DistancePath *a, const DistancePath *b) {
                                    return a->peso < b->peso;
                                });

            DistancePath *currentMin = *it;
            pendingNodesV.erase(it);

            // Procesar todos los vecinos del nodo actual
            NodoGrafo *currentGraphNode = pGrafo->getHashNodos()->at(currentMin->keyNode->getId());
            for (Arco *arco : *currentGraphNode->getArcos()) {
                NodoGrafo *vecino = static_cast<NodoGrafo *>(arco->getDestino());
                int newDist = currentMin->peso + arco->getPeso();

                // Actualizar la distancia si es menor
                auto vecinoDP = find_if(pendingNodesV.begin(), pendingNodesV.end(),
                                        [vecino](const DistancePath *dp) {
                                            return dp->keyNode == vecino->getInfo();
                                        });

                if (vecinoDP != pendingNodesV.end() && newDist < (*vecinoDP)->peso) {
                    (*vecinoDP)->peso = newDist;
                    (*vecinoDP)->LastNodo = currentMin->keyNode;
                }
            }

            // Mover el nodo a processedNodesF
            processedNodesF.push_back(currentMin);
        }

        // Reconstruir el camino más corto
        Path *shortestPath = new Path();
        shortestPath->origen = pOrigen;
        shortestPath->destino = pDestino;
        INodo *currentNode = pDestino;

        while (currentNode != pOrigen) {
            shortestPath->path.insert(shortestPath->path.begin(), currentNode);
            auto it = find_if(processedNodesF.begin(), processedNodesF.end(),
                            [currentNode](const DistancePath *dp) {
                                return dp->keyNode == currentNode;
                            });

            if (it == processedNodesF.end()) {
                // No se encontró un camino
                delete shortestPath;
                return nullptr;
            }

            currentNode = (*it)->LastNodo;
        }

        shortestPath->path.insert(shortestPath->path.begin(), pOrigen);
        return shortestPath;
    }


private:
};

#endif