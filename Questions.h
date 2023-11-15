#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <iostream>
#include "GraphDiscover.h"
#include "INodo.h"
#include "grafo.h"

class Questions {
public:
    void Pregunta2(INodo* pOrigen, INodo* pDestino, Grafo* pGrafo) {
        GraphDiscover gd;
        Path* ruta = gd.getShorterPath(pOrigen, pDestino, pGrafo);

        if (ruta != nullptr) {
            std::cout << "La ruta mas corta desde la Camara hasta el Cargador es: ";
            for (INodo* nodo : ruta->path) {
                std::cout << nodo->getGear() << " -> ";
            }
            std::cout << "Fin" << std::endl;

            delete ruta;
        } else {
            std::cout << "No se encontro una ruta." << std::endl;
        }
    }
};

#endif
