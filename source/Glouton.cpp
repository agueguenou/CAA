#include "../include/Algorithmes.h"

vector<int> glouton(const Graph *graph){
    vector<int> VertexCover;
    Graph *copy = graph->copy();

    while(!copy->haveNoEdge()){
        int vertexMaxNbEdge = 0;
        for (int i = 1; i<copy->getNbVertex(); i++){
            if(copy->getNbEdge(i) > copy->getNbEdge(vertexMaxNbEdge))
            {
                vertexMaxNbEdge = i;
            }
        }
        VertexCover.push_back(vertexMaxNbEdge);
        copy->delVertex(vertexMaxNbEdge);
    }
    return VertexCover;
}

