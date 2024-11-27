#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>


using namespace std;

class Grafo {
public:
    vector<vector<int>> Lista; 
    map<string, int> MapaNombres;
    vector<string> Nombres; 
    void agregarNodo(const string& nombre);
    void agregarConexion(const string& a, const string& b); 
    vector<string> bfs(const string& inicio); 

};

#endif
