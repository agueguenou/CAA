#include "../include/Algorithmes.h"

bool isInCover(vector<int> vertexCover, int vertex){
	bool result = false;

	vector<int>::iterator it = vertexCover.begin() ;
	while((it != vertexCover.end()) && (!result)){
        //result passe à vrai si Vertex est dans la couverture et on sort
		result = ((*it) == vertex);
		it++;
	}
	return result;
}

bool testCover(Graph* g, vector<int> vertexCover){
	bool result = true;
	int i = 0;

	while(( i < g->getNbVertex()) && (result)) {
		int currentVertex = i;
		if(!isInCover(vertexCover, currentVertex)) {
            //Si le sommet n'est pas dans la couverture
			vector<int> adjVertices = g->getNeighbours(currentVertex);
			vector<int>::iterator it = adjVertices.begin();
            //On parcours tout ses sommets adjacents
			while((it != adjVertices.end()) && (result)){
                //result passe à faux si un des sommets adj n'est pas dans la couverture
				result = result && isInCover(vertexCover, (*it));
				it++;
			}
		}
		i++;
	}
	return result;
}

bool vertexCoverRecur(Graph *graph, int coverSize, vector<int>& vertexCover){
	bool result = false;
	int currentCoverSize = coverSize - 1;

	if(coverSize > 0) {
		int i = 0;
		vertexCover.push_back(i);
		while(( i < graph->getNbVertex()) && (!result)) {
			vertexCover.pop_back();
            vertexCover.push_back(i);
			result = vertexCoverRecur(graph, currentCoverSize, vertexCover);
			i++;
		}
		if(!result){
			vertexCover.pop_back();
		}
	}
	else {
		result = testCover(graph, vertexCover);
	}

	return result;
}

vector<int> opti_para_minCoverGraph(const Graph *graph, int coverSize){

    vector<int> vertexCover;
    vector<int> properVertexCover;
    Graph *copy = graph->copy();

    bool result = vertexCoverRecur(copy, coverSize, vertexCover);

    //Si on ne trouve pas de couverture minimale de la taille demandée on efface le tableau
	if(!result){
		vertexCover.clear();
	}
	else{
        //On parcours la couverture pour enlever les doublons
        int j = 0;
        properVertexCover.push_back(vertexCover[0]);
        for(int i = 1; i < (signed)vertexCover.size(); i++){
            if(vertexCover[i]!=vertexCover[j])
                properVertexCover.push_back(vertexCover[i]);
            j++;
        }
	}

    return properVertexCover;
}
