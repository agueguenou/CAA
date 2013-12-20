#include <iostream>

#include "include/Graph.h"
#include "include/Random_graph.h"
#include "include/Random_bipartis.h"
#include "include/Random_Tree.h"
#include "include/Random_Binary_Tree.h"
#include "include/Random_minCoverGraph.h"
#include "include/Algorithmes.h"
#include "include/ReaderFile.h"
#include "include/Minisat.h"
#include <vector>

using namespace std;

void displayVector(vector<int> v) {
    vector<int>::iterator it;
    cout << " ";
    for (it = v.begin(); it != v.end(); ++it) {
            cout << *it + 1 << "  ";
    }
    cout << endl;
}

int main()
{
   
    cout<<endl;
    cout<<endl;
    Graph* g4 = new RandomTree(10,1,5);
    cout<< "////////////////////////////////////////////////////////////////////////////////" << endl;
    cout<< "///////////////////////////////Arbre aléatoire//////////////////////////////////" <<endl;
    cout<< "////////////////////////////////////////////////////////////////////////////////" << endl<<endl<<endl;
    cout<< g4->toString() << endl<<endl;
    cout<<"Algorithme de recherche de couverture:\n"<<endl;
    vector<int> cover51 = GetTreeOptimalVertexCover(g4);
    cout << "> Arbre optimal :";
    displayVector(cover51);


    cout<<endl;
    cout<<endl;
    Graph* g3 = new RandomBinaryTree(10);
    cout<< "////////////////////////////////////////////////////////////////////////////////" << endl;
    cout<< "//////////////////////////////Arbre aléatoire binaire///////////////////////////" <<endl;
    cout<< "////////////////////////////////////////////////////////////////////////////////" << endl<<endl<<endl;
    cout<<  g3->toString() << endl<<endl;
    cout<<"Algorithme de recherche de couverture:\n"<<endl;
    vector<int> cover41 = GetTreeOptimalVertexCover(g3);
    cout << "> Arbre optimal :";
    displayVector(cover41);



    cout<<endl;
    cout<<endl;
    Graph* g = new Random_graph(5, 0.5);
    cout<< "////////////////////////////////////////////////////////////////////////////////" << endl;
    cout<< "///////////////////////////////Graph classique//////////////////////////////////"<<endl; 
    cout<< "////////////////////////////////////////////////////////////////////////////////" << endl<<endl<<endl;
    cout<<g->toString() << endl<<endl;

    cout<<"Algorithme de recherche de couverture:\n"<<endl;
    vector<int> cover = glouton(g);
    cout<<"> Glouton : ";displayVector(cover);

    vector<int> cover2 = twoAppr_neighbourhood(g);
    cout<<"> 2-approché avec élimination du voisin : ";
    displayVector(cover2);

    vector<int> cover3 = twoAppr_depthSearch(g);
    cout<<"> 2-approché avec parcours en profondeur : ";
    displayVector(cover3);

    cout<<endl;
    cout<<endl;
    Graph* g2 = new Random_bipartis(10, 1);
    cout<< "////////////////////////////////////////////////////////////////////////////////" << endl;
    cout<< "///////////////////////////////Graph bipartis///////////////////////////////////" <<endl;
    cout<< "////////////////////////////////////////////////////////////////////////////////" << endl<<endl<<endl;
    cout<< g2->toString() << endl<<endl;


  
    cout<<endl;
    cout<<endl;
    Graph *g7 = new Random_minCoverGraph(10,3,0.8);
    cout<< "////////////////////////////////////////////////////////////////////////////////" << endl;
    cout<< "////////////////////////Graph ayant une petite couverture///////////////////////" <<endl;
    cout<< "////////////////////////////////////////////////////////////////////////////////" << endl<<endl<<endl;
    cout << g7->toString() << endl;
    cout<<"Algorithme de recherche de couverture:\n"<<endl;
    vector<int> cover_para = opti_para_minCoverGraph(g7, 3);
    cout << "Optimale paramétrique (3) : ";
    displayVector(cover_para);


    

    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<< "////////////////////////////////////////////////////////////////////////////////" << endl;
    cout<< "///////////////////////////////File to Graph////////////////////////////////////" << endl;
    cout<< "////////////////////////////////////////////////////////////////////////////////" << endl<<endl<<endl;
    ReaderFile* reader = new ReaderFile();
    Graph *grapheFile = new Graph();
    grapheFile = reader->fileToGraph("source/fileTest.txt");
	
    cout << "Graph normal :\n" << grapheFile->toString() << endl;


    
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<< "////////////////////////////////////////////////////////////////////////////////" << endl;
    cout<< "//////////////////////////////SAT-solver MiniSat////////////////////////////////" <<endl;
    cout<< "////////////////////////////////////////////////////////////////////////////////" << endl<<endl<<endl;
    Minisat minsat = Minisat();
    minsat.VertexCoverToSat(grapheFile);
    minsat.SatToVertexCover();


	
    return 0;

}
