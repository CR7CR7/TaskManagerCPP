
#pragma once
#include <string>
#include <vector>
#include "task.h"
#include <sqlite3.h>

class Database {
public:
    Database(const std::string& dbPath);
    ~Database();

    bool init();
    bool addTask(const Task& task);
    std::vector<Task> getAllTasks();
    bool updateTask(int id, bool completed);
    bool deleteTask(int id);

private:
    sqlite3* db;
    std::string path;
};
