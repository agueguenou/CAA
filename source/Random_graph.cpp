#include "../include/Random_graph.h"

#include <time.h>
#include <cstdlib>

Random_graph::Random_graph()
{
    //Création par défaut d'un graphe avec 5 sommets et 1 chance sur 2 de créer une arrête
    generateRandomGraph(5, 0.5);
}

Random_graph::Random_graph(int nbVertex, float probaEdge)
{
    generateRandomGraph(nbVertex, probaEdge);
}

Random_graph::~Random_graph()
{
    //dtor
}

void Random_graph::generateRandomGraph(int nbVertex, float probaEdge){

    srand(time(NULL));
    if (nbVertex < 1)
            return;
    int i = addVertex();
    while (i < nbVertex-1){
        i = addVertex();
        for (int j=i-1; j>=0; j--) {
            double randomNumber = rand()/(double)RAND_MAX;
            if(randomNumber < probaEdge)
                addEdge(j, i);
        }
    }
}
