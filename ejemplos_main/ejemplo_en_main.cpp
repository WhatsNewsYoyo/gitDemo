#include "../UserManager.hpp"
#include <iostream>

int main() {
    UserManager manager;
    
    manager.addUser("Juan");
    manager.addUser("Ana");
    manager.addUser("Pedro");

    manager.addInterest("Juan", "Deportes", "Futbol");
    manager.addInterest("Juan", "Deportes", "Tenis");
    manager.addInterest("Juan", "Música", "Rock");

    manager.addInterest("Ana", "Arte", "Pintura");
    manager.addInterest("Ana", "Arte", "Escultura");
    manager.addInterest("Ana", "Música", "Jazz");

    // Hacer aamigos
    manager.addFriend("Juan", "Ana");
    manager.addFriend("Juan", "Pedro");

    User* juan = manager.getUser("Juan");
    if(juan != nullptr) {
        // Mostrar nombre
        std::cout << "Usuario: " << juan->name << std::endl;
        
        // Mostrar todos sus intereses
        std::cout << "\nIntereses de Juan:" << std::endl;
        for(const std::string& interest : juan->interests) {
            std::cout << "- " << interest << std::endl;
        }

        // Mostrar intereses categorizados
        std::cout << "\nIntereses por categoria:" << std::endl;
        for(const auto& catInterest : juan->categorizedInterests) {
            std::cout << catInterest[0] << ": " << catInterest[1] << std::endl;
        }

        // Mostrar amigos
        std::cout << "\nAmigos de Juan:" << std::endl;
        for(const std::string& friendName : juan->friendNames) {
            std::cout << "- " << friendName << std::endl;
        }
    }

    return 0;
}