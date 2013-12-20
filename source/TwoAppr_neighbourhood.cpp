#include "../include/Algorithmes.h"

vector<int> twoAppr_neighbourhood(const Graph *graph){
    vector<int> vertexCover;
    Graph *copy = graph->copy();

    int current_vertex = 0;
    int adj_vertex = 0;

    while(!copy->haveNoEdge()) {
        if(copy->getNbEdge(current_vertex)!=0){
          adj_vertex = copy->getNeighbours(current_vertex)[0];
          vertexCover.push_back(current_vertex);
          vertexCover.push_back(adj_vertex);
          copy->delVertex(current_vertex);
          copy->delVertex(adj_vertex);
        }
        else{
            current_vertex++;
        }
    }
    return vertexCover;
}

