#include <iostream>
#include "Grafo.h"
#include "Gear.h"
#include "Questions.h"

int main() {
    /*cout << "--------------------------- TESTING DFS ---------------------------\n" << std::endl;
    // Crear un grafo
    Grafo grafo(true);

    // Crear algunos nodos
    Gear nodo1, nodo2, nodo3, nodo4, nodo5, nodo6, nodo7, nodo8, nodo9, nodo10, nodo11, nodo12, nodo13,
        nodo14, nodo15, nodo16, nodo17, nodo18, nodo19, nodo20;

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
    nodo18.setGear("Estuche");
    nodo19.setGear("Correa");
    nodo20.setGear("Cable");

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
    NodoGrafo* grafoNodo18 =  grafo.addNode(&nodo18);
    NodoGrafo* grafoNodo19 =  grafo.addNode(&nodo19);
    NodoGrafo* grafoNodo20 =  grafo.addNode(&nodo20);

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
    grafo.addArc(grafoNodo3, grafoNodo18);
    grafo.addArc(grafoNodo18, grafoNodo19);
    grafo.addArc(grafoNodo19, grafoNodo20);
    grafo.addArc(grafoNodo20, grafoNodo18);
    grafo.addArc(grafoNodo5, grafoNodo11);
    grafo.addArc(grafoNodo11, grafoNodo16);
    grafo.addArc(grafoNodo16, grafoNodo9);
    grafo.addArc(grafoNodo9, grafoNodo5);

    // Llamar al método deepPath y guardar el resultado
    vector<INodo*> path = grafo.deepPath(&nodo1);

    // Imprimir el resultado
    for (vector<INodo*>::iterator it = path.begin(); it != path.end(); ++it){
        INodo* nodo = *it;
        cout << "Nodo: " << nodo->getId() << std::endl;
    }*/

    cout << "--------------------------- TESTING SCC ---------------------------\n" << std::endl;
    // Create a new graph
    Grafo sccGraph(true);

    // Create some nodes
    Gear camera, lens, tripod, flash, memoryCard, filter, bag, tripodhead, strap, remote, 
    reflector, flashDifussor, lensCleningKit, cameraCleaningKit, backdrop, gimbal, battery;


    camera.setGear("Camera");
    lens.setGear("Lens");
    tripod.setGear("Tripod");
    flash.setGear("Flash");
    memoryCard.setGear("Memory Card");
    filter.setGear("Filter");
    bag.setGear("Bag");
    tripodhead.setGear("Tripod Head");
    strap.setGear("Strap");
    remote.setGear("Remote");
    reflector.setGear("Reflector");
    flashDifussor.setGear("Flash Difussor");
    lensCleningKit.setGear("Lens Clening Kit");
    cameraCleaningKit.setGear("Camera Cleaning Kit");
    backdrop.setGear("Backdrop");
    gimbal.setGear("Gimbal");
    battery.setGear("Battery");

    // Get the corresponding NodoGrafo for each Gear
    NodoGrafo* sccGrafoNode1 = sccGraph.addNode(&camera);
    NodoGrafo* sccGrafoNode2 = sccGraph.addNode(&lens);
    NodoGrafo* sccGrafoNode3 = sccGraph.addNode(&tripod);
    NodoGrafo* sccGrafoNode4 = sccGraph.addNode(&flash);
    NodoGrafo* sccGrafoNode5 = sccGraph.addNode(&memoryCard);
    NodoGrafo* sccGrafoNode6 = sccGraph.addNode(&filter);
    NodoGrafo* sccGrafoNode7 = sccGraph.addNode(&bag);
    NodoGrafo* sccGrafoNode8 = sccGraph.addNode(&tripodhead);
    NodoGrafo* sccGrafoNode9 = sccGraph.addNode(&strap);
    NodoGrafo* sccGrafoNode10 = sccGraph.addNode(&remote);
    NodoGrafo* sccGrafoNode11 = sccGraph.addNode(&reflector);
    NodoGrafo* sccGrafoNode12 = sccGraph.addNode(&flashDifussor);
    NodoGrafo* sccGrafoNode13 = sccGraph.addNode(&lensCleningKit);
    NodoGrafo* sccGrafoNode14 = sccGraph.addNode(&cameraCleaningKit);
    NodoGrafo* sccGrafoNode15 = sccGraph.addNode(&backdrop);
    NodoGrafo* sccGrafoNode16 = sccGraph.addNode(&gimbal);
    NodoGrafo* sccGrafoNode19 = sccGraph.addNode(&battery);

    // Create some arcs between the nodes
    sccGraph.addArcWeight(sccGrafoNode1, sccGrafoNode2, 10); // Cámara y Lente (uso obligatorio)
    sccGraph.addArcWeight(sccGrafoNode2, sccGrafoNode3, 8);  // Lente y Trípode (muy probable)
    sccGraph.addArcWeight(sccGrafoNode3, sccGrafoNode4, 6);  // Trípode y Flash (probable)
    sccGraph.addArcWeight(sccGrafoNode4, sccGrafoNode5, 3);  // Flash y Tarjeta de Memoria (poco probable)
    sccGraph.addArcWeight(sccGrafoNode5, sccGrafoNode6, 7);  // Tarjeta de Memoria y Filtro (probable)
    sccGraph.addArcWeight(sccGrafoNode6, sccGrafoNode7, 9);  // Filtro y Bolsa (muy probable)
    sccGraph.addArcWeight(sccGrafoNode7, sccGrafoNode8, 2);  // Bolsa y Cabeza de Trípode (poco probable)
    sccGraph.addArcWeight(sccGrafoNode8, sccGrafoNode9, 4);  // Cabeza de Trípode y Correa (moderadamente probable)
    sccGraph.addArcWeight(sccGrafoNode9, sccGrafoNode10, 5); // Correa y Control Remoto (moderadamente probable)
    sccGraph.addArcWeight(sccGrafoNode10, sccGrafoNode11, 1); // Control Remoto y Reflector (muy poco probable)
    sccGraph.addArcWeight(sccGrafoNode11, sccGrafoNode12, 6); // Reflector y Difusor de Flash (probable)
    sccGraph.addArcWeight(sccGrafoNode12, sccGrafoNode13, 4); // Difusor de Flash y Kit de Limpieza de Lentes (moderadamente probable)
    sccGraph.addArcWeight(sccGrafoNode13, sccGrafoNode14, 2); // Kit de Limpieza de Lentes y Kit de Limpieza de Cámara (poco probable)
    sccGraph.addArcWeight(sccGrafoNode14, sccGrafoNode15, 3); // Kit de Limpieza de Cámara y Fondo (poco probable)
    sccGraph.addArcWeight(sccGrafoNode15, sccGrafoNode16, 7); // Fondo y Gimbal (probable)
    sccGraph.addArcWeight(sccGrafoNode16, sccGrafoNode1, 5);  // Gimbal y Cámara (moderadamente probable)
    sccGraph.addArcWeight(sccGrafoNode1, sccGrafoNode4, 9);  // Cámara y Flash (muy probable)
    sccGraph.addArcWeight(sccGrafoNode6, sccGrafoNode9, 3);  // Filtro y Correa (poco probable)
    sccGraph.addArcWeight(sccGrafoNode11, sccGrafoNode14, 5); // Reflector y Kit de Limpieza de Cámara (moderadamente probable)
    sccGraph.addArcWeight(sccGrafoNode16, sccGrafoNode3, 7);  // Gimbal y Trípode (probable)
    sccGraph.addArcWeight(sccGrafoNode2, sccGrafoNode6, 7); // Lente a Filtro
    sccGraph.addArcWeight(sccGrafoNode6, sccGrafoNode19, 1); // Filtro a Batería
    sccGraph.addArcWeight(sccGrafoNode19, sccGrafoNode7, 7); // Batería a Bolsa

    // Cycles
    // sccGraph.addArcWeight(sccGrafoNode1, sccGrafoNode2, 10); // Cámara a Lente
    //sccGraph.addArcWeight(sccGrafoNode2, sccGrafoNode6, 8);  // Lente a Filtro
    sccGraph.addArcWeight(sccGrafoNode6, sccGrafoNode5, 5);  // Filtro a Tarjeta de Memoria
    sccGraph.addArcWeight(sccGrafoNode5, sccGrafoNode4, 9);  // Tarjeta de Memoria a Flash
    sccGraph.addArcWeight(sccGrafoNode4, sccGrafoNode1, 6);  // Flash a Cámara

    sccGraph.addArcWeight(sccGrafoNode1, sccGrafoNode7, 5);  // Cámara a Bolsa
    sccGraph.addArcWeight(sccGrafoNode7, sccGrafoNode3, 4);  // Bolsa a Trípode
    sccGraph.addArcWeight(sccGrafoNode3, sccGrafoNode6, 3);  // Trípode a Batería
    //sccGraph.addArcWeight(sccGrafoNode6, sccGrafoNode7, 2);  // Batería a Cargador
    sccGraph.addArcWeight(sccGrafoNode7, sccGrafoNode1, 6);  // Bolsa a Cámara
    
    // Call the StronglyConnectedComponents method and store the result
    vector<vector<INodo*>> sccs = sccGraph.StronglyConnectedComponents();

    // Print the result
    for (int i = 0; i < sccs.size(); ++i) {
        for (INodo* nodo : sccs[i]) {
            cout <<"\n"<< nodo->getId() << " "<< nodo->getGear() << " // ";
        }
        cout << endl;
    }
                                      //PREGUNTAS POR REALIZAR
    Questions q;
    cout << "\n1. Cuales son todas las posibles combinaciones de equipo que puedo llevar desde la Cámara hasta el Cargador, considerando todas las posibilidades de equipo intermedio que podríamos necesitar llevar?\n" << endl;

    cout << "\n2. Si estamos limitados en espacio y necesitamos transportar el equipo de la manera mas eficiente posible, cual es la ruta mas corta para llevar el equipo desde la Camara hasta el Cargador?\n" << endl;
    q.Pregunta2(&camera, &battery, &sccGraph);

    cout << "--------------FIN---------------" << endl;
    return 0;
}