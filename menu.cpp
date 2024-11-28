#include <iostream>
#include "ContentManager.h"
#include "graph.h"
#include "recommendation_system.hpp"

using namespace std;

void CrearAmisatad1(RecommendationSystem& system) {
    cout << "Agregar amigos mutuos!\nAmigo 1: ";
    std::string input;
    cin >> input;

    cout << "Amigo 2: ";
    std::string input2;
    cin >> input2;

    std::cout << "\n";
    
    system.addFriend(input, input2);
}

void Agregarinteres3(UserManager& users) {
    cout << "Usuario: ";
    std::string input;
    std::cin >> input;

    cout << "Interés: ";
    std::string input2;
    std::cin >> input2;

    users.addInterest(input, input2);
}

void VerRecomendaciones4(RecommendationSystem& system) {
    std::cout << "Recomendaciones de usuario: ";
    std::string input;
    std::cin >> input;
    std::cout << "\nRecomendaciones: \n";

    for(auto i: system.recommendContent(input)){
        std::cout << i << "\n";
    }

    std::cout << "\n";
}

void AgregarUsuario5(RecommendationSystem& system) {
    cout << "Escriba el nombre del usuario al que quiera añadir: \n";

    std::string input;
    cin >> input;
    
    system.addUser(input);
}

void CrearContenido(ContentManager& manager){
    std::cout << "Ingrese una categoría: ";

    std::string input;
    cin >> input;

    cout << "Ingrese el contenido: ";
    std::string input2;
    cin >> input2;

    manager.addContent(input, input2);
}

void EliminarAmisatad(Grafo& graph){
    cout << "Eliminar amistad :(\nNo_Amigo 1: ";
    std::string input;
    cin >> input;

    cout << "No_Amigo 2: ";
    std::string input2;
    cin >> input2;

    graph.eliminarConexion(input, input2);
}

int main() {
    int opcion;
    ContentManager manager;
    UserManager users;
    Grafo graph;
    RecommendationSystem recommendations(&users, &graph, &manager);
    string categoria, contenido, objeto;

    do {
        // Mostrar menú
        cout << "===== MENÚ =====\n";
        cout << "1. Crear amistad\n";
        cout << "2. Agregar contenido\n";
        cout << "3. Agregar interés a un usuario\n";
        cout << "4. Ver recomendaciones\n";
        cout << "5. Agregar usuario\n";
        cout << "6. Lista de usuarios\n";
        cout << "7. Eliminar amistad\n";
        cout << "8. Salir \nInput: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                CrearAmisatad1(recommendations);
                break;
            case 2:
                CrearContenido(manager);
                break;
            case 3:
                Agregarinteres3(users);
                break;
            case 4:
                VerRecomendaciones4(recommendations);
                break;
            case 5:
                AgregarUsuario5(recommendations);
                break;
            case 6:
                std::cout << "\nUSUARIOS---------\n";
                for(auto i: graph.Nombres){
                    std::cout << i << "\n";
                }
                std::cout << "\n";
                break;

            case 7:
                EliminarAmisatad(graph);
                break;
            case 8:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opción no valida. Por favor, intenta de nuevo.\n";
                break;
        }

        cout << endl; // Separador para mejor visualización
    } while (opcion != 8);

    return 0;
}
