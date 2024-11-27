#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class CategoryManager {
private:
    unordered_map<string, vector<string>> categorias; // Mapa de categorías y sus objetos

public:
    // Método para agregar una nueva categoría
    void addCategory(const string& categoria) {
        if (categorias.find(categoria) == categorias.end()) {
            categorias[categoria] = {}; // Crear una categoría vacía
            cout << "Categoría '" << categoria << "' agregada.\n";
        } else {
            cout << "La categoría '" << categoria << "' ya existe.\n";
        }
    }
    
 };