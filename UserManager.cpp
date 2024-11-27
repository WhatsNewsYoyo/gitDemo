#include "UserManager.hpp"

void UserManager::addUser(std::string name) {
    users.push_back(User(name));
}


//regresa un puntero al usuario en el vector
User* UserManager::getUser(std::string name) {
    for(auto& user : users) { 
        if(user.name == name) {
            return &user;  
        }
    }
    return nullptr;
}

//selecciona un usuario con base en el nombre, a su vector de intereses le agrega un nuevo interes
void UserManager::addInterest(std::string username, std::string category, std::string interest) {
    User* user = getUser(username);
    if(user != nullptr) {
        user->interests.push_back(interest);
        user->categorizedInterests.push_back({category, interest});
    }
}

//selecciona dos usuarios con base en sus nombres y los agrega a la lista de amigos de cada uno
void UserManager::addFriend(std::string username1, std::string username2) {
    User* user1 = getUser(username1);
    User* user2 = getUser(username2);
    
    if(user1 != nullptr && user2 != nullptr) {
        user1->friendNames.push_back(username2);
        user2->friendNames.push_back(username1);
    }
}


std::vector<std::string> UserManager::getInterests(std::string username) {
    User* user = getUser(username);
    if(user != nullptr) {
        return user->interests;
    }
    return std::vector<std::string>();
}


//esta funcion no la usamos creo
std::vector<std::vector<std::string>> UserManager::getCategorizedInterests(std::string username) {
    User* user = getUser(username);
    if(user != nullptr) {
        return user->categorizedInterests;
    }
    return std::vector<std::vector<std::string>>();
}


//regresa un vector con los nombres de los amigos de un usuario
std::vector<std::string> UserManager::getFriendNames(std::string username) {
    User* user = getUser(username);
    if(user != nullptr) {
        return user->friendNames;
    }
    return std::vector<std::string>();
}