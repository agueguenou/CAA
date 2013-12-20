#include "../include/Random_bipartis.h"

#include <time.h>
#include <cstdlib>
#include <iostream>
Random_bipartis::Random_bipartis()
{
    generateRandomBipartis(5, 0.5);
}

Random_bipartis::Random_bipartis(int nbVertex, float probaEdge)
{
    generateRandomBipartis(nbVertex, probaEdge);
}

Random_bipartis::~Random_bipartis()
{
    //dtor
}

void Random_bipartis::generateRandomBipartis(int nbVertex, float probaEdge){

    srand(time(NULL));
    //quantité max de sommet dans la 1ère des deux parties
    int sizeFirstSet = rand() % (nbVertex - 1) + 1;

    for (int i = 0; i <nbVertex; i++)
        addVertex();

	for (int i = 0; i < sizeFirstSet; i++) {
		for (int j = sizeFirstSet; j < nbVertex; j++) {
			double randomNumber = rand()/(double)RAND_MAX;
            if(randomNumber < probaEdge){
                addEdge(i,j);
			}
		}
	}
    //défaut de cette implémentation : si la proba n'est pas de 1, il peut y avoir des sommets sans arrêtes.
    //Une solution pourrait être de rajouter le code ci-dessous:
    for(int i = 0; i < nbVertex; i++){
        if(getNbEdge(i)==0){
            if(i<sizeFirstSet){
                //alors c'est un sommet du 1er set, on le relis à un du 2ème set
                addEdge(i,((rand() % (nbVertex-sizeFirstSet)) + sizeFirstSet));
            }
            else{
                addEdge(i,(rand() % sizeFirstSet));
            }
        }
    }
}
