#ifndef RANDOM_MINCOVERGRAPH_H
#define RANDOM_MINCOVERGRAPH_H

#include "../include/Graph.h"

class Random_minCoverGraph : public Graph
{
    public:
        Random_minCoverGraph();
        Random_minCoverGraph(int nbVertex, int coverSize, float probaEdge);
        virtual ~Random_minCoverGraph();
    private:
        void generateRandomMinCoverGraph(int nbVertex, int coverSize, float probaEdge);
};

#endif // RANDOM_MINCOVERGRAPH_H
