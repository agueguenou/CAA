#include "../include/Random_Tree.h"
#include <time.h>
#include <cstdlib>
#include <cmath>

RandomTree::RandomTree(int nbVertex,int min,int max) : Graph()
{
        generateRandomTree(nbVertex,min,max);
	
}



void
RandomTree::generateRandomTree(int nbVertex,int nbMinChild,int nbMaxChild) {
        srand(time(NULL));
	if (nbVertex < 1)
                return;

	int nbNodesCreated = 1;
	int cursor = addVertex();

	while (nbNodesCreated < (nbVertex)) {
		
		int maxRand;

		if (nbMaxChild > (nbVertex - (nbNodesCreated - 1)))
			maxRand = (nbVertex - (nbNodesCreated - 1));
		else
			maxRand = nbMaxChild;
		int nbChildren = rand() % (maxRand - nbMinChild) + nbMinChild;

		if (nbChildren > 0) {
			for (int i = 0; i < nbChildren; i++) {
				nbNodesCreated=addVertex();
				addEdge(cursor, nbNodesCreated);
				nbNodesCreated++;
			}
			cursor++;
		}
	}

}

