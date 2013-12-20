
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>


#include <iomanip>
#include <fstream>
#include <istream>

#include "../include/ReaderFile.h"

ReaderFile::ReaderFile(){
}

ReaderFile::~ReaderFile(){
}

Graph* ReaderFile::fileToGraph(char* file){


	int number_of_lines = 0;
 	std::string line;
    	std::ifstream myfile(file);

   	while (std::getline(myfile, line))
	{
       
        ++number_of_lines;
	}

	Graph* g = new Graph();
	
	//Création Sommet
   	for(int i = 0;i<number_of_lines;i++){

	g->addVertex();	
	}

	//Création Arrêtes


    
    std::string line2;
    std::ifstream myfile2(file);
    int rootVertex = 0;
    while (std::getline(myfile2, line2))
    {

       
       //string to char*
       char *buffer=new char[line2.size()+1];
       buffer[line2.size()]=0;
       memcpy(buffer,line2.c_str(),line2.size());

       //Calcul de la position de ':'
       int position=0;

       position =2;

       //Ajout des Arrêtes
       for(int i=position+1;i<=(signed)strlen(buffer);i++){


           if (buffer[i] >= '0' && buffer[i] <= '9'){
              int newVertex = buffer[i]-'0';

            if(!g->isNeighbour(rootVertex,newVertex-1)){
                g->addEdge(rootVertex,newVertex-1);
            }

           }
       }


        rootVertex++;
    }
	return g;
}




