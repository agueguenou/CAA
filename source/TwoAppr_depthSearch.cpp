#include "../include/Algorithmes.h"
#include <map>
#include <vector>
#include <stack>

#define WHITE   0
#define GREY   1
#define BLACK     2

using namespace std;


bool isColor(int vertex, int color, map<int, int> &vertexColor){
	return (vertexColor[vertex] == color);
}

void colorVertex(int vertex, int color, map<int, int> &vertexColor){
	vertexColor[vertex] = color;
}

//Version non récursive
vector<int> twoAppr_depthSearch(const Graph *graph){
    vector<int> vertexCover;
    Graph *copy = graph->copy();
    Graph* tmpGraph = new Graph();
    map<int, int> vertexColor;
    stack<int> p;

    if(copy->getNbVertex() > 0){

        //On met tous les sommets à blanc
        for (int i=0 ; i < copy->getNbVertex(); i++){
            colorVertex(i, WHITE, vertexColor);
            tmpGraph->addVertex();
        }

        //Premier element
        int current_vertex = 0;
        colorVertex(current_vertex, GREY, vertexColor);
        p.push(current_vertex);
        while (!p.empty()){
            current_vertex = p.top();
            p.pop();
            if (!isColor(current_vertex, BLACK, vertexColor)){
                colorVertex(current_vertex, BLACK, vertexColor);
                 for(int i = 0; i< (signed)copy->getNeighbours(current_vertex).size(); i++) {
                    int adj_vertex = copy->getNeighbours(current_vertex)[i];
                    if (!isColor(adj_vertex, BLACK, vertexColor)) {
                        colorVertex(adj_vertex, GREY, vertexColor);
                        p.push(adj_vertex);
                        tmpGraph->addOnlyOneEdge(current_vertex, adj_vertex);
                    }
                }
            }
        }
    }
    //Suppression des sommets qui n'ont pas d'arrête
    for (int i=0 ; i < tmpGraph->getNbVertex(); i++){
		if (tmpGraph->getNbEdge(i)>0){
			vertexCover.push_back(i);
		}
    }

    return vertexCover;
}
