#ifndef RECOMMENDATION
#define RECOMMENDATION

#include "UserManager.hpp"
#include "graph.h"
#include "ContentManager.h"
#include <iostream>
#include <vector>

class RecommendationSystem{
public:
    RecommendationSystem(UserManager* my_user_manager, Grafo* my_graph, ContentManager* my_content_manager);
    std::vector<std::string> recommendContent(std::string user);
    void addUser(std::string user);
    void addContent(std::string category, std::string content);
    void addFriend(std::string user, std::string friendd);
private:
    bool user_exists(std::string user);
    UserManager* _my_user_manager;
    Grafo* _my_graph;
    ContentManager* _my_content_manager;
};

#endif
