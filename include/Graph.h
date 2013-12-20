#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

using namespace std;

class Graph
{
    protected:
        vector<vector<int> > g_vertex;
    public:
        Graph();
        Graph(vector<vector<int> > g_vertex);
        virtual ~Graph();

	vector< vector<int> > getVectorFromGraph() const;
        int getNbVertex() const;
        int addVertex();
        void delVertex(int vertex);

        int getNbEdge(int vertex) const;
        void addEdge(int vertex, int vertex2);
        void addOnlyOneEdge(int vertex, int vertex2);
        void delEdge(int vertex1, int vertex2);

        bool haveEdge(int vertex1, int vertex2);
        bool haveNoEdge();

        vector<int> getNeighbours(int vertex) const;
	bool isNeighbour(int vertex,int vertex2);

        string toString();

        Graph *copy() const;
};

#endif // GRAPH_H
