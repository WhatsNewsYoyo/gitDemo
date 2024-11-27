#ifndef CONTENT_MANAGER_H
#define CONTENT_MANAGER_H

#include <string>
#include <vector>
#include <unordered_map>

class ContentManager {
private:
    std::unordered_map<std::string, std::vector<std::string>> categoryContent;

public:
    void addContent(const std::string& category, const std::string& content);
    std::vector<std::string> getContentByCategory(const std::string& category) const;
};

#endif
