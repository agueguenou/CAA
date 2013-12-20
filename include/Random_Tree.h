#ifndef RANDOMTREE_H_
#define RANDOMTREE_H_

#include "Graph.h"

class RandomTree : public Graph {
public:
        RandomTree(int nbVertex,int min,int max);
private:
        void generateRandomTree(int nbVertex,int min,int max);
	
};

#endif /* TREE_H_ */
