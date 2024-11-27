#include "ContentManager.h"
#include <iostream>
using namespace std;

// agregar una nueva categoría
void CategoryManager::addCategory(const string& categoria) {
    if (categorias.find(categoria) == categorias.end()) {
        categorias[categoria] = {}; 
        cout << "Categoría '" << categoria << "' agregada.\n";
    } else {
        cout << "La categoría '" << categoria << "' ya existe.\n";
    }
}

// agregar un objeto a una categoría
void CategoryManager::addObjectToCategory(const string& categoria, const string& object) {
    if (categorias.find(categoria) != categorias.end()) {
        categorias[categoria].push_back(object);
        cout << "Objeto '" << object << "' agregado a la categoría '" << categoria << "'.\n";
    } else {
        cout << "Error: La categoría '" << categoria << "' no existe.\n";
    }
}
