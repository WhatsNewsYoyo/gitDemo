#include <iostream>
#include "graph.h"
using namespace std;



void Grafo::agregarNodo(const string& nombre) {
    if (MapaNombres.find(nombre) == MapaNombres.end()) { 
        MapaNombres[nombre] = Nombres.size(); 
        Nombres.push_back(nombre);
        Lista.emplace_back();
    }
}

void Grafo::agregarConexion(const string& a, const string& b) {

    agregarNodo(a);
    agregarNodo(b);

    int indiceA = MapaNombres[a];  
    int indiceB = MapaNombres[b]; 

    //Bidireccional
    Lista[indiceA].push_back(indiceB); 
    Lista[indiceB].push_back(indiceA);
}

//Metodo BFS
vector<string> Grafo::bfs(const string& inicio) {
    
    vector<string> resultado;
    
    //Si no hay nada
    if (MapaNombres.find(inicio) == MapaNombres.end()) { 
        return resultado; 
    }

    vector<bool> visitado(Nombres.size(), false);
    queue<int> q;

    int nodoInicio = MapaNombres[inicio]; 
    q.push(nodoInicio);
    visitado[nodoInicio] = true;

    while (!q.empty()) {
        int actual = q.front();
        q.pop();
        resultado.push_back(Nombres[actual]);

        for (int vecino : Lista[actual]) {
            if (!visitado[vecino]) {
                q.push(vecino);
                visitado[vecino] = true;
            }
        }
    }

    return resultado; 
}
