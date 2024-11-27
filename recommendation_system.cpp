#include "recommendation_system.hpp"

RecommendationSystem::RecommendationSystem(UserManager* my_user_manager):
_my_user_manager(my_user_manager){
    update_system();
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
            std::vector<std::string> this_interest_vector = _users[i].interests;
            final_interest_vec.insert(final_interest_vec.end(), this_interest_vector.begin(), this_interest_vector.end());
        }
    }

    return final_interest_vec;
}

int RecommendationSystem::find_by_name(std::string name) {
    for (int i = 0; i < _users.size(); i++){
        if(_users[i].name == name) return i;
    }
    return -1;
}

void RecommendationSystem::get_users_from_manager(){
    _users = _my_user_manager -> get_users_vector();
    update_system();
}


void RecommendationSystem::update_system(){

    int users_s = _users.size();
    std::vector<std::vector<int>> new_system(users_s, std::vector<int>(users_s, INT_MAX));

    _system = new_system;

    for(int i = 0; i < users_s; i++){
        for(auto friendd : _users[i].friendNames){
            _system[i][find_by_name(friendd)] = 1;
        }
    }
}