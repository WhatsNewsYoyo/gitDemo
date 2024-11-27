#ifndef CATEGORY_MANAGER_H
#define CATEGORY_MANAGER_H

#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class CategoryManager {
private:
    unordered_map<string, vector<string>> categorias; // Mapa de categorías y sus objetos

public:
    // Método para agregar una nueva categoría
    void addCategory(const string& categoria);

    // Método para agregar un objeto a una categoría
    void addObjectToCategory(const string& categoria, const string& object);
};

#endif
