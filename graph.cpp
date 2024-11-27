#include <iostream>
#include <algorithm>
#include "graph.h"
using namespace std;

void Grafo::agregarNodo(const string& nombre) {
    // Buscar si el nombre ya existe en el mapa
    // find() regresa un iterador al final del mapa si no encuentra el elemento
    if (MapaNombres.find(nombre) != MapaNombres.end()) {
        cout << "Error: El usuario '" << nombre << "' ya existe" << endl;
        return;
    }
    // Agregar nuevo mapeo: el índice será el tamaño actual del vector Nombres
    MapaNombres[nombre] = Nombres.size();
    // Agregar el nombre al vector de nombres
    Nombres.push_back(nombre);
    // Agregar un nuevo vector vacío a la lista de adyacencia
    // emplace_back() construye un nuevo vector vacío al final
    Lista.emplace_back();
}

void Grafo::agregarConexion(const string& a, const string& b) {
    // Verificar que no sea el mismo usuario
    if (a == b) {
        cout << "Error: No se permite agregar a un usuario como su mismo amigo" << endl;
        return;
    }

    // Verificar que ambos usuarios existan
    // Si alguno no existe, find() regresará el iterador end()
    if (MapaNombres.find(a) == MapaNombres.end() || 
        MapaNombres.find(b) == MapaNombres.end()) {
        cout << "Error: Uno o ambos usuarios no existen" << endl;
        return;
    }

    // Obtener los índices correspondientes del mapeo
    int indiceA = MapaNombres[a];
    int indiceB = MapaNombres[b];

    // Verificar si la conexión ya existe usando find()
    // find() busca el valor indiceB en el vector de conexiones de A
    if (find(Lista[indiceA].begin(), Lista[indiceA].end(), indiceB) != Lista[indiceA].end()) {
        cout << "La conexión ya existe" << endl;
        return;
    }

    // Agregar las conexiones bidireccionales
    Lista[indiceA].push_back(indiceB);  
    Lista[indiceB].push_back(indiceA);  
}

void Grafo::eliminarConexion(const string& a, const string& b) {
    // Verificar que ambos usuarios existan
    if (MapaNombres.find(a) == MapaNombres.end() || 
        MapaNombres.find(b) == MapaNombres.end()) {
        cout << "Error: Uno o ambos usuarios no existen" << endl;
        return;
    }

    // Obtener los índices
    int indiceA = MapaNombres[a];
    int indiceB = MapaNombres[b];

    // Obtener referencia al vector de conexiones de A
    auto& listaA = Lista[indiceA];
    // Buscar la conexión con B
    auto itA = find(listaA.begin(), listaA.end(), indiceB);
    // Si se encuentra, eliminarla
    if (itA != listaA.end()) {
        listaA.erase(itA);
    }

    // Repetir el proceso para eliminar la conexión de B a A
    auto& listaB = Lista[indiceB];
    auto itB = find(listaB.begin(), listaB.end(), indiceA);
    if (itB != listaB.end()) {
        listaB.erase(itB);
    }
}

vector<string> Grafo::bfs(const string& inicio) {
    vector<string> resultado;
    
    // Verificar si el usuario existe
    if (MapaNombres.find(inicio) == MapaNombres.end()) {
        cout << "Error: El usuario '" << inicio << "' no existe" << endl;
        return resultado;
    }

    // Inicialización para BFS
    vector<bool> visitado(Nombres.size(), false);  // Marcar todos como no visitados
    queue<int> cola;  // Cola para BFS
    
    int nodoInicio = MapaNombres[inicio];
    cola.push(nodoInicio);  // Agregar nodo inicial a la cola
    visitado[nodoInicio] = true;  // Marcar como visitado

    // Mientras la cola no esté vacía
    while (!cola.empty()) {
        int actual = cola.front();  // Obtener el primer elemento
        cola.pop();  // Remover el elemento de la cola
        
        // Si no es el nodo inicial, agregarlo al resultado
        if (actual != nodoInicio) {
            resultado.push_back(Nombres[actual]);
        }

        // Como solo queremos profundidad 1, no agregamos los vecinos a la cola
        // Solo procesamos los vecinos si el nodo actual es el nodo inicial
        if (actual == nodoInicio) {
            for (int vecino : Lista[actual]) {
                if (!visitado[vecino]) {
                    cola.push(vecino);
                    visitado[vecino] = true;
                }
            }
        }
    }

    return resultado;
}