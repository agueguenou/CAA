#include "Graph.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

class Minisat {
private:



      void computeFile(int numberVertex, vector<pair<int,int> > listVertice );



public:
        // Constructeur (default)
        Minisat();
        void VertexCoverToSat(Graph* g);
        void startMinisat();
          vector<int> SatToVertexCover();
        virtual ~Minisat();

        bool coverComputed;
};
