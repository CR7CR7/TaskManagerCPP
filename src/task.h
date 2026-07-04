#pragma once
#include <string>

struct Task {
    int id;
    std::string title;
    std::string description;
    bool completed;

    Task(int id_, const std::string& t, const std::string& d, bool c = false)
        : id(id_), title(t), description(d), completed(c) {}
};
