
#include "database.h"
#include <sqlite3.h>
#include <stdexcept>

Database::Database(const std::string& dbPath)
    : db(nullptr), path(dbPath) {
    if (sqlite3_open(path.c_str(), reinterpret_cast<sqlite3**>(&db)) != SQLITE_OK) {
        throw std::runtime_error("Failed to open database");
    }
}

Database::~Database() {
    if (db) {
        sqlite3_close(reinterpret_cast<sqlite3*>(db));
    }
}

bool Database::init() {
    const char* sql =
        "CREATE TABLE IF NOT EXISTS tasks ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "title TEXT NOT NULL,"
        "description TEXT,"
        "completed INTEGER NOT NULL DEFAULT 0);";

    char* errMsg = nullptr;
    int rc = sqlite3_exec(reinterpret_cast<sqlite3*>(db), sql, nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}

bool Database::addTask(const Task& task) {
    const char* sql =
        "INSERT INTO tasks (title, description, completed) VALUES (?, ?, ?);";

    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(reinterpret_cast<sqlite3*>(db), sql, -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, task.title.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, task.description.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 3, task.completed ? 1 : 0);

    bool success = sqlite3_step(stmt) == SQLITE_DONE;
    sqlite3_finalize(stmt);
    return success;
}

std::vector<Task> Database::getAllTasks() {
    std::vector<Task> tasks;
    const char* sql = "SELECT id, title, description, completed FROM tasks;";

    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(reinterpret_cast<sqlite3*>(db), sql, -1, &stmt, nullptr);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        std::string title(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        std::string description(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        bool completed = sqlite3_column_int(stmt, 3) != 0;

        tasks.emplace_back(id, title, description, completed);
    }

    sqlite3_finalize(stmt);
    return tasks;
}

bool Database::updateTask(int id, bool completed) {
    const char* sql = "UPDATE tasks SET completed = ? WHERE id = ?;";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(reinterpret_cast<sqlite3*>(db), sql, -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, completed ? 1 : 0);
    sqlite3_bind_int(stmt, 2, id);

    bool success = sqlite3_step(stmt) == SQLITE_DONE;
    sqlite3_finalize(stmt);
    return success;
}

bool Database::deleteTask(int id) {
    const char* sql = "DELETE FROM tasks WHERE id = ?;";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(reinterpret_cast<sqlite3*>(db), sql, -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, id);

    bool success = sqlite3_step(stmt) == SQLITE_DONE;
    sqlite3_finalize(stmt);
    return success;
}
