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
    
    //Para guardar los amigos
    vector<string> resultado;
    
    //Si no hay nada
    if (MapaNombres.find(inicio) == MapaNombres.end()) { 
        return resultado; 
    }

    vector<bool> visitado(Nombres.size(), false);
    queue<int> fila;


    int nodoInicio = MapaNombres[inicio]; 
    fila.push(nodoInicio);
    visitado[nodoInicio] = true;

    //Mientras exista la queue
    while (!fila.empty()) {
        int actual = fila.front();
        //Quitar
        fila.pop();
        resultado.push_back(Nombres[actual]);

        for (int vecino : Lista[actual]) {
            if (!visitado[vecino]) {
                fila.push(vecino);
                visitado[vecino] = true;
            }
        }
    }

    return resultado; 
}
