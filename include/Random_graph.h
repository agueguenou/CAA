#ifndef RANDOM_GRAPH_H
#define RANDOM_GRAPH_H

#include "../include/Graph.h"

class Random_graph : public Graph
{
    public:
        Random_graph();
        Random_graph(int nbVertex, float probaEdge);
        virtual ~Random_graph();
    private:
        void generateRandomGraph(int nbVertex, float probaEdge);
};

#endif // RANDOM_GRAPH_H
