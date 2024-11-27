#ifndef USER_MANAGER_H
#define USER_MANAGER_H

#include <string>
#include <vector>
#include <unordered_map>

class UserManager {
private:
    std::unordered_map<std::string, std::vector<std::string>> userInterests;

public:
    void addUser(const std::string& username);
    void addInterest(const std::string& username, const std::string& interest);
    std::vector<std::string> getInterests(const std::string& username);
};

#endif