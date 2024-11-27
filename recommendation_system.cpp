#include <iostream>

struct user
{
    std::string name;
    std::vector<user*> friends;
    std::vector<std::string> interests = {"cool_interest", "interest_2"};
};

int find_index(const std::vector<user*>& vec, user* element) {
    auto it = std::find(vec.begin(), vec.end(), element);
    if (it != vec.end()) {
        return std::distance(vec.begin(), it);
    }
    return -1;

}

class RecommendationSystem{
public:
    void addUser(std::string new_user);
    void addContent();
    void addFriend(std::string the_user, std::string his_friend);
    std::vector<std::string> recommendContent(std::string user);
    void update_system();
    std::vector<std::vector<int>> _system;
private:
    std::vector<user*> _users;
    std::vector<std::string> _contents;

    int find_by_name(std::string name);

};

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
    _users.push_back(new user);
    _users.back() -> name = new_user;
    update_system();
}

void RecommendationSystem::addFriend(std::string the_user, std::string his_friend){
    user* friend_ptr = _users[find_by_name(the_user)];
    _users[find_by_name(the_user)]->friends.push_back(friend_ptr);
    update_system();
}


void RecommendationSystem::update_system(){

    int users_s = _users.size();
    std::vector<std::vector<int>> new_system(users_s, std::vector<int>(users_s, INT_MAX));

    _system = new_system;

    for(int i = 0; i < users_s; i++){
        for(auto friendd : _users[i] -> friends){
            _system[i][find_index(_users, friendd)] = 1;
        }
    }
}

int main(){
    RecommendationSystem a;
    a.addUser("danilo");
    a.addUser("juan");
    a.addUser("damian");
    a.addUser("lol");
    a.addFriend("danilo","juan");
    
    a.addFriend("juan","danilo");
    a.addFriend("juan","damian");

    for(auto i: a.recommendContent("juan")){
        std::cout << i << "\n";
    }
}