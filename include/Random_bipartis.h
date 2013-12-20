#ifndef RANDOM_BIPARTIS_H
#define RANDOM_BIPARTIS_H

#include "../include/Graph.h"

class Random_bipartis : public Graph
{
    public:
        Random_bipartis();
        Random_bipartis(int nbVertex, float probaEdge);
        virtual ~Random_bipartis();
    private:
        void generateRandomBipartis(int nbVertex, float probaEdge);
};

#endif // RANDOM_BIPARTIS_H
