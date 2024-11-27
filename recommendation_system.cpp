#include <iostream>

struct user
{
    std::string name;
    std::vector<user*> friends;

};

int findIndex(const std::vector<user*>& vec, user* element) {
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
    void addFriend();
    void recommendContent();
private:
    std::vector<user*> _users;
    std::vector<std::string> _contents;

    std::vector<std::vector<int>> _system;

    void update_system();

};

void RecommendationSystem::addUser(std::string new_user){
    _users.push_back(new user);
    _users.back() -> name = new_user;
    
}

void RecommendationSystem::update_system(){

    int users_s = _users.size();

    std::vector<std::vector<int>> new_system(users_s, std::vector<int>(users_s));

    for(int i = 0; i < users_s; i++){
        for(auto friendd : _users[i] -> friends){
            _system[i][findIndex(_users, friendd)];
        }
    }
}

int main(){

}