#ifndef RECOMMENDATION
#define RECOMMENDATION

#include "UserManager.hpp"
#include <iostream>
#include <vector>

class RecommendationSystem{
public:
    void addUser(std::string new_user);
    void addContent();
    void addFriend(std::string the_user, std::string his_friend);
    std::vector<std::string> recommendContent(std::string user);
    void update_system();
    std::vector<std::vector<int>> _system;
    std::vector<User*> _users;
private:
    std::vector<std::string> _contents;

    int find_by_name(std::string name);

};

#endif
