#include "graphTest.h"
#include <sstream>
#include <assert.h>  
#include <stdio.h>      /* printf */
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
#include <math.h> 
#include "../include/Graph.h"
#include "../include/Random_graph.h"
#include "../include/Random_bipartis.h"
#include "../include/Random_Tree.h"
#include "../include/Random_Binary_Tree.h"
#include "../include/Random_minCoverGraph.h"
#include "../include/Algorithmes.h"
#include "../include/ReaderFile.h"
#include "../include/Minisat.h"

//Constructeur par défaut
GraphTest::GraphTest()
{
  
}

void GraphTest::runTest()
{ 

  cout<<"-------------------GRAPH TEST UNITAIRES-----------------"<<endl;
	
  Graph *g = new Random_graph(5, 0.5);
  assert(g->getNbVertex() == 5);
  cout<<"TestNbVertex SUCCESSFULL"<<endl;

 g->addVertex();
	assert(g->getNbVertex() == 6);
  cout<<"TestaddVertex SUCCESSFULL"<<endl;

 g->delVertex(5);

  assert(g->getNeighbours(5).size()== 0);
  cout<<"TestdelVertex SUCCESSFULL"<<endl;

 
 Graph* g1 = new Graph();
    g1->addVertex();g1->addVertex();g1->addVertex();g1->addVertex();g1->addVertex();
    g1->addEdge(0,1);g1->addEdge(0,2);g1->addEdge(1,2);g1->addEdge(2,3);g1->addEdge(3,4);
    assert(g1->getNbEdge(0)== 2);
    cout<<"TestgetNbEdge() SUCCESSFULL"<<endl;


    g1->addEdge(0,3);
	 assert(g1->getNbEdge(0)== 3);
	 	 cout<<"Test addEdge() SUCCESSFULL"<<endl;

    g1->delEdge(0, 3);
	assert(g1->getNbEdge(0)== 2);
	 	 cout<<"Test delEdge() SUCCESSFULL"<<endl;

	
	assert(g1->haveEdge(0, 1) == true);
	assert(g1->haveEdge(0, 4) == false);
	cout<<"Test haveEdge() SUCCESSFULL"<<endl;

    
	assert(g1->isNeighbour(0,1) == true);
	assert(g1->isNeighbour(0,4) == false);
	cout<<"Test isNeighbour() SUCCESSFULL"<<endl;

cout<<"-------------------TEST PERFORMANCE-----------------"<<endl;
 clock_t start;
    double duration;
Graph *g2 = new Random_graph(1000, 0.5);
     Graph *g5 = new RandomBinaryTree(2000);
start = clock();      
  
  printf ("Génération Calculating...\n");
 
 
  GetTreeOptimalVertexCover(g5);
   
  
  duration = (clock() - start ) / (double) CLOCKS_PER_SEC;

   
  printf ("TreeOptimal 1000 Sommets : %f seconds\n",duration);

////////////////////////////
start = clock();      
  
  printf ("Génération Calculating...\n");
 
 
  twoAppr_neighbourhood(g2);
   
  
  duration = (clock() - start ) / (double) CLOCKS_PER_SEC;

   
  printf ("twoAppr_neighbourhood 1000 Sommets : %f seconds\n",duration);

//////////////////////////

start = clock();      
  
  printf ("Génération Calculating...\n");
 
 
  twoAppr_depthSearch(g2);
   
  
  duration = (clock() - start ) / (double) CLOCKS_PER_SEC;

   
  printf ("twoAppr_depthSearch 1000 Sommets : %f seconds\n",duration);


start = clock();      
  
  printf ("Génération Calculating...\n");
 
 
  glouton(g2);
   
  
  duration = (clock() - start ) / (double) CLOCKS_PER_SEC;

   
  printf ("glouton 1000 Sommets : %f seconds\n",duration);
	


	

Graph *g3 = new Random_graph(2000, 0.5);
Graph *g4 = new RandomBinaryTree(2000);
start = clock();      
  
  printf ("Génération Calculating...\n");
 
 
  GetTreeOptimalVertexCover(g4);
   
  
  duration = (clock() - start ) / (double) CLOCKS_PER_SEC;

   
  printf ("TreeOptimal 2000 Sommets : %f seconds\n",duration);

////////////////////////////
start = clock();      
  
  printf ("Génération Calculating...\n");
 
 
  twoAppr_neighbourhood(g3);
   
  
  duration = (clock() - start ) / (double) CLOCKS_PER_SEC;

   
  printf ("twoAppr_neighbourhood 2000 Sommets : %f seconds\n",duration);

//////////////////////////

start = clock();      
  
  printf ("Génération Calculating...\n");
 
 
  twoAppr_depthSearch(g3);
   
  
  duration = (clock() - start ) / (double) CLOCKS_PER_SEC;

   
  printf ("twoAppr_depthSearch 2000 Sommets : %f seconds\n",duration);


start = clock();      
  
  printf ("Génération Calculating...\n");
 
 
  glouton(g3);
   
  
  duration = (clock() - start ) / (double) CLOCKS_PER_SEC;

   
  printf ("glouton 2000 Sommets : %f seconds\n",duration);
	


	
}





