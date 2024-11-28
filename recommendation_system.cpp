#include "recommendation_system.hpp"

RecommendationSystem::RecommendationSystem(UserManager* my_user_manager, Grafo* my_graph, ContentManager* my_content_manager):
_my_user_manager(my_user_manager), _my_content_manager(my_content_manager), _my_graph(my_graph){}

bool RecommendationSystem::user_exists(std::string user){
    if (_my_graph->MapaNombres.find(user) == _my_graph->MapaNombres.end()) {
        return 0;
    }
    return 1;
}

std::vector<std::string> RecommendationSystem::recommendContent(std::string user) {
    if(!user_exists(user)){
        std::cout << "user not found.\n";
        return {};
    }
    
    std::vector<std::string> content_vec;
    std::vector<std::string> connections = _my_graph->bfs(user);
    for(auto friendd: connections){
        std::vector<std::string> category = _my_user_manager -> getInterests(friendd);
        for(auto interest: category){
            std::vector<std::string> content_topic = _my_content_manager->getContentByCategory(interest);
            content_vec.insert(content_vec.end(), content_topic.begin(), content_topic.end());
        }
    }

    return content_vec;
}

void RecommendationSystem::addUser(std::string user){
    if(user_exists(user)){
        std::cout << "can not create duplicate user.\n";
    }
    _my_graph->agregarNodo(user);
    _my_user_manager->addUser(user);

    std::cout << "Nuevo usuario - " << user << "!\n";
}

void RecommendationSystem::addContent(std::string category, std::string content){
    _my_content_manager -> addContent(category, content);
    std::cout << "Se agrego nuevo contenido a la categoria - " << category << "!\n";
}

void RecommendationSystem::addFriend(std::string user, std::string friendd){
    if(!user_exists(user) || !user_exists(friendd)){
        std::cout << "one or both users are non_existent.\n";
        return;
    }

    _my_graph -> agregarConexion(user, friendd);
    std::cout << "se creo la amistad entre " << user << " y " << friendd << "!\n";
}