#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <queue>
#include <string>

#include <unordered_map>

using namespace std;

class Grafo {
public:
    vector<vector<int>> Lista; 
    unordered_map<string, int> MapaNombres;
    vector<string> Nombres; 
    void agregarNodo(const string& nombre);
    void agregarConexion(const string& a, const string& b); 
    vector<string> bfs(const string& inicio); 
    Grafo();
};

#endif
