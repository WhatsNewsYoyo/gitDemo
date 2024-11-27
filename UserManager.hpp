#ifndef USER_MANAGER_H
#define USER_MANAGER_H

#include <string>
#include <vector>

struct User {
    std::string name;
    // Lista simple de todos los intereses
    std::vector<std::string> interests;
    // Lista organizada [categoria, interes]
    std::vector<std::vector<std::string>> categorizedInterests;
    std::vector<std::string> friendNames;  
    
    User(std::string userName) {
        name = userName;
    }
};

class UserManager {
private:
    std::vector<User> users;  

public:
    // Funciones principales
    void addUser(std::string name);
    void addInterest(std::string username, std::string category, std::string interest);
    void addFriend(std::string username1, std::string username2);
    
    // Funciones para obtener datos
    User* getUser(std::string name);  // Retorna puntero al usuario en el vector
    std::vector<std::string> getInterests(std::string username);
    std::vector<std::vector<std::string>> getCategorizedInterests(std::string username);
    std::vector<std::string> getFriendNames(std::string username);
};

#endif