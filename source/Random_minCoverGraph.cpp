#include "../include/Random_minCoverGraph.h"

#include <time.h>
#include <cstdlib>

Random_minCoverGraph::Random_minCoverGraph()
{
    //Création par défaut d'un graphe avec 5 sommets et 1 chance sur 2 de créer une arrête
    generateRandomMinCoverGraph(5, 5, 0.5);
}

Random_minCoverGraph::Random_minCoverGraph(int nbVertex, int coverSize, float probaEdge)
{
    generateRandomMinCoverGraph(nbVertex,coverSize, probaEdge);
}

Random_minCoverGraph::~Random_minCoverGraph()
{
    //dtor
}

void Random_minCoverGraph::generateRandomMinCoverGraph(int nbVertex, int coverSize, float probaEdge){

    srand(time(NULL));

    for (int i = 0; i <nbVertex; i++)
        addVertex();
    //On créer des arrêtes seulement entre sommets : couvrant/couvrant et couvrant/non-couvrant
    //tous les sommets
	for (int i = 0; i < nbVertex; i++) {
        //seulement les sommets couvrant
		for (int j = 0; j < coverSize; j++) {
			double randomNumber = rand()/(double)RAND_MAX;
            if(randomNumber < probaEdge && i!=j && !haveEdge(i, j)){
                addEdge(i,j);
			}
		}
	}
}
