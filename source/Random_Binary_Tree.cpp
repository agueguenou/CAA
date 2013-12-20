#include "../include/Random_Binary_Tree.h"
#include <time.h>
#include <cstdlib>
#include <cmath>

const int nbMinChild = 0;
const int nbMaxChild = 3;




RandomBinaryTree::RandomBinaryTree(int nbVertex) : Graph()
{
        generateRandomBinaryTree(nbVertex,nbMinChild,nbMaxChild);
	
}



void
RandomBinaryTree::generateRandomBinaryTree(int nbVertex,int nbMinChild,int nbMaxChild) {
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
