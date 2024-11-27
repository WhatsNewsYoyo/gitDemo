#ifndef RECOMMENDATION
#define RECOMMENDATION

#include "UserManager.hpp"
#include <iostream>
#include <vector>

class RecommendationSystem{
public:
    RecommendationSystem(UserManager* my_user_manager);
    std::vector<std::string> recommendContent(std::string user);
    void update_system();
    void get_users_from_manager();
private:

    std::vector<std::vector<int>> _system;
    std::vector<User> _users;
    std::vector<std::string> _contents;
    int find_by_name(std::string name);

    UserManager* _my_user_manager;
};

#endif
