#include <iostream>
#include "Grafo.h"
#include "Gear.h"

int main() {
    cout << "--------------------------- TESTING DFS ---------------------------\n" << std::endl;
    // Crear un grafo
    Grafo grafo(true);

    // Crear algunos nodos
    Gear nodo1, nodo2, nodo3, nodo4, nodo5, nodo6, nodo7, nodo8, nodo9, nodo10, nodo11, nodo12, nodo13,
        nodo14, nodo15, nodo16, nodo17;

    nodo1.setGear("Camara");
    nodo2.setGear("Luces");
    nodo3.setGear("Carry Bag");
    nodo4.setGear("Tripode");
    nodo5.setGear("Lentes");
    nodo6.setGear("Bateria");
    nodo7.setGear("Cargador");
    nodo8.setGear("Memoria");
    nodo9.setGear("Filtro");
    nodo10.setGear("Flash");
    nodo11.setGear("Lente2");
    nodo12.setGear("Bateria2");
    nodo13.setGear("Cargador2");
    nodo14.setGear("Memoria2");
    nodo15.setGear("Filtro2");
    nodo16.setGear("Flash2");
    nodo17.setGear("Lente3");

    // Obtener los NodoGrafo correspondientes a los Gear
    NodoGrafo* grafoNodo1 =  grafo.addNode(&nodo1);
    NodoGrafo* grafoNodo2 =  grafo.addNode(&nodo2);
    NodoGrafo* grafoNodo3 =  grafo.addNode(&nodo3);
    NodoGrafo* grafoNodo4 =  grafo.addNode(&nodo4);
    NodoGrafo* grafoNodo5 =  grafo.addNode(&nodo5);
    NodoGrafo* grafoNodo6 =  grafo.addNode(&nodo6);
    NodoGrafo* grafoNodo7 =  grafo.addNode(&nodo7);
    NodoGrafo* grafoNodo8 =  grafo.addNode(&nodo8);
    NodoGrafo* grafoNodo9 =  grafo.addNode(&nodo9);
    NodoGrafo* grafoNodo10 =  grafo.addNode(&nodo10);
    NodoGrafo* grafoNodo11 =  grafo.addNode(&nodo11);
    NodoGrafo* grafoNodo12 =  grafo.addNode(&nodo12);
    NodoGrafo* grafoNodo13 =  grafo.addNode(&nodo13);
    NodoGrafo* grafoNodo14 =  grafo.addNode(&nodo14);
    NodoGrafo* grafoNodo15 =  grafo.addNode(&nodo15);
    NodoGrafo* grafoNodo16 =  grafo.addNode(&nodo16);
    NodoGrafo* grafoNodo17 =  grafo.addNode(&nodo17);

    // Crear algunos arcos entre los nodos
    grafo.addArc(grafoNodo1, grafoNodo3);
    grafo.addArc(grafoNodo2, grafoNodo5);
    grafo.addArc(grafoNodo3, grafoNodo7);
    grafo.addArc(grafoNodo4, grafoNodo8);
    grafo.addArc(grafoNodo5, grafoNodo10);
    grafo.addArc(grafoNodo6, grafoNodo11);
    grafo.addArc(grafoNodo7, grafoNodo13);
    grafo.addArc(grafoNodo8, grafoNodo14);
    grafo.addArc(grafoNodo9, grafoNodo15);
    grafo.addArc(grafoNodo10, grafoNodo16);
    grafo.addArc(grafoNodo11, grafoNodo17);
    grafo.addArc(grafoNodo12, grafoNodo1);
    grafo.addArc(grafoNodo13, grafoNodo4);
    grafo.addArc(grafoNodo14, grafoNodo2);
    grafo.addArc(grafoNodo15, grafoNodo6);
    grafo.addArc(grafoNodo16, grafoNodo9);
    grafo.addArc(grafoNodo17, grafoNodo12);
    grafo.addArc(grafoNodo1, grafoNodo10);
    grafo.addArc(grafoNodo1, grafoNodo2);

    // Llamar al método deepPath y guardar el resultado
    vector<INodo*> path = grafo.deepPath(&nodo1);

    // Imprimir el resultado
    for (vector<INodo*>::iterator it = path.begin(); it != path.end(); ++it){
        INodo* nodo = *it;
        cout << "Nodo: " << nodo->getId() << std::endl;
    }

    cout << "--------------------------- TESTING SCC ---------------------------\n" << std::endl;
    // Create a new graph
    Grafo sccGraph(true);

    // Create some nodes
    Gear sccNode1, sccNode2, sccNode3, sccNode4, sccNode5;

    // Get the corresponding NodoGrafo for each Gear
    NodoGrafo* sccGrafoNode1 = sccGraph.addNode(&sccNode1);
    NodoGrafo* sccGrafoNode2 = sccGraph.addNode(&sccNode2);
    NodoGrafo* sccGrafoNode3 = sccGraph.addNode(&sccNode3);
    NodoGrafo* sccGrafoNode4 = sccGraph.addNode(&sccNode4);
    NodoGrafo* sccGrafoNode5 = sccGraph.addNode(&sccNode5);

    // Create some arcs between the nodes to form cycles
    sccGraph.addArc(sccGrafoNode1, sccGrafoNode2);
    sccGraph.addArc(sccGrafoNode2, sccGrafoNode3);
    sccGraph.addArc(sccGrafoNode3, sccGrafoNode1);  // This forms a cycle with nodes 1, 2, and 3
    sccGraph.addArc(sccGrafoNode4, sccGrafoNode5);
    sccGraph.addArc(sccGrafoNode5, sccGrafoNode4);  // This forms a cycle with nodes 4 and 5

    // Call the StronglyConnectedComponents method and store the result
    vector<vector<INodo*>> sccs = sccGraph.StronglyConnectedComponents();

    // Print the result
    for (int i = 0; i < sccs.size(); ++i) {
        cout << "SCC " << i + 1 << ": ";
        for (INodo* nodo : sccs[i]) {
            cout << nodo->getId() << " ";
        }
        cout << endl;
    }

    return 0;
}