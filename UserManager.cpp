#include "UserManager.hpp"
#include <iostream>

void UserManager::addUser(const std::string& username) {
    if (userInterests.find(username) != userInterests.end()) {
        std::cout << "Error: El usuario ya existe" << std::endl;
        return;
    }
    userInterests[username] = std::vector<std::string>();
}

void UserManager::addInterest(const std::string& username, const std::string& interest) {
    if (userInterests.find(username) == userInterests.end()) {
        std::cout << "Error: Usuario no encontrado" << std::endl;
        return;
    }
    userInterests[username].push_back(interest);
}

std::vector<std::string> UserManager::getInterests(const std::string& username) {
    if (userInterests.find(username) == userInterests.end()) {
        std::cout << "Error: Usuario no encontrado" << std::endl;
        return std::vector<std::string>();
    }
    return userInterests.at(username);
}