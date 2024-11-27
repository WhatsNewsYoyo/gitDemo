#include <iostream>

struct user
{
    std::string name;
    std::vector<user*> friends;

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
private:
    std::vector<user*> _users;
    std::vector<std::string> _contents;

    std::vector<std::vector<int>> _system;

    void update_system();
    int find_by_name(std::string name);

};

int RecommendationSystem::recommendContent(std::string user) {
    find_by_name[user];
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
}

void RecommendationSystem::addFriend(std::string the_user, std::string his_friend){
    user* friend_ptr = _users[find_by_name(the_user)];
    _users[find_by_name(the_user)]->friends.push_back(friend_ptr);
}


void RecommendationSystem::update_system(){

    int users_s = _users.size();
    std::vector<std::vector<int>> new_system(users_s, std::vector<int>(users_s));

    for(int i = 0; i < users_s; i++){
        for(auto friendd : _users[i] -> friends){
            _system[i][find_index(_users, friendd)];
        }
    }
}

int main(){

}