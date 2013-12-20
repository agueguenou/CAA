#include "../include/Algorithmes.h"


static
void Depth_First_Search_Tree(vector< vector<int> > & G, vector<bool> & visited, vector<bool> & matched, vector<int> & vertexCover, int current)
{
  visited[current] = true;


  for(unsigned int i = 0; i < G[current].size(); i++)
    {
      int childNode = G[current][i];
      if( !visited[childNode] )
	{
	 Depth_First_Search_Tree(G, visited, matched, vertexCover, childNode);


	  if(!matched[childNode] && !matched[current])
	    {
	      matched[current] = true;
	      matched[childNode] = true;
	      vertexCover.push_back(current);
	    }
	}
    }
}


static
vector<int> Initialize_Depth_First_Search(vector< vector<int> > & g)
{
  vector<bool> visited(g.size(), false);
  vector<bool> matched(g.size(), false);
  vector<int> vertexCover;


  int start = 0; 
  Depth_First_Search_Tree(g, visited, matched, vertexCover, start);


  return vertexCover;
}

vector<int> GetTreeOptimalVertexCover( const Graph * g){
  vector< vector<int> >  G = g->getVectorFromGraph();
  return Initialize_Depth_First_Search(G);
}

