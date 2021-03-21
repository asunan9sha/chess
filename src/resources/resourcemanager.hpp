
#ifndef CHESS_RESOURCEMANAGER_HPP
#define CHESS_RESOURCEMANAGER_HPP

#include "pch.hpp"

template<typename R>
class ResourceManager {
public:
    explicit ResourceManager(const std::string &folder) : folder_(folder) {}

    const R &get(const std::string &name, bool isFullPath = false) {
        if (!exists(name)) {
            R r;
            std::string str = isFullPath ? name : folder_ + name;

            if (!r.loadFromFile(str)) {
                exit(0xDEAD);
            }
            resources_.emplace(name, r);
        }
        return resources_[name];
    }

    void remove(const std::string &name) {
        resources_.erase(name);
    }

private:
    bool exists(const std::string &name) {
        return resources_.find(name) != resources_.end();
    }

private:
    std::unordered_map<std::string, R> resources_;
    std::string folder_;
};


#endif
