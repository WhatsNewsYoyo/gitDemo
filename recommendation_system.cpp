#include "recommendation_system.hpp"


int find_index(const std::vector<User*>& vec, User* element) {
    auto it = std::find(vec.begin(), vec.end(), element);
    if (it != vec.end()) {
        return std::distance(vec.begin(), it);
    }
    return -1;

}

std::vector<std::string> RecommendationSystem::recommendContent(std::string user) {
    int user_index = find_by_name(user);

    if(user_index == -1){
        std::cout << "user_not_found\n";
        return {};
    }

    std::vector<std::string> final_interest_vec;

    for(int i = 0; i < _system[user_index].size(); i++){
        if (_system[user_index][i] != INT_MAX){
            std::vector<std::string> this_interest_vector = _users[i] -> interests;
            final_interest_vec.insert(final_interest_vec.end(), this_interest_vector.begin(), this_interest_vector.end());
        }
    }

    return final_interest_vec;
}

int RecommendationSystem::find_by_name(std::string name) {
    for (int i = 0; i < _users.size(); i++){
        if(_users[i]->name == name) return i;
    }
    return -1;
}

void RecommendationSystem::addUser(std::string new_user){
    _users.push_back(new User(new_user));
    update_system();
}

void RecommendationSystem::addFriend(std::string the_user, std::string his_friend){
    _users[find_by_name(the_user)]->friendNames.push_back(his_friend);
    update_system();
}


void RecommendationSystem::update_system(){

    int users_s = _users.size();
    std::vector<std::vector<int>> new_system(users_s, std::vector<int>(users_s, INT_MAX));

    _system = new_system;

    for(int i = 0; i < users_s; i++){
        for(auto friendd : _users[i] -> friendNames){
            _system[i][find_by_name(friendd)] = 1;
        }
    }
}