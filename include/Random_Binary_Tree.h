#ifndef RANDOMBINARYTREE_H_
#define RANDOMBINARYTREE_H_

#include "Graph.h"

class RandomBinaryTree : public Graph {
public:
        RandomBinaryTree(int nbVertex);

private:
	void generateRandomBinaryTree(int nbVertex,int nbMinChild,int nbMaxChild);
	
};

#endif /* RANDOMBINARYTREE_H_ */
