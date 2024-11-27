#include "ContentManager.h"
#include <iostream>

void ContentManager::addContent(const std::string& category, const std::string& content) {
    //si no existe la categoria, la creamos
    if (categoryContent.find(category) == categoryContent.end()) {
        categoryContent[category] = std::vector<std::string>();
    }
    categoryContent[category].push_back(content);
}

std::vector<std::string> ContentManager::getContentByCategory(const std::string& category) const {
    //si no existe la categoria, devolvemos un vector vacio
    //si existe, devolvemos el contenido de la categoria
    if (categoryContent.find(category) == categoryContent.end()) {
        std::cout << "Error: Categoria no encontrada" << std::endl;
        return std::vector<std::string>();
    }
    return categoryContent.at(category);
}