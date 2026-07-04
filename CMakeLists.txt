cmake_minimum_required(VERSION 3.10)
project(TaskManagerCPP)

set(CMAKE_CXX_STANDARD 17)

# Boost (Beast е header-only, but must installed)
find_package(Boost REQUIRED COMPONENTS system thread beast)

# SQLite
find_package(SQLite3 REQUIRED)

# Catch2 v3
find_package(Catch2 REQUIRED)

# -----------------------------
# Main executable
# -----------------------------
add_executable(TaskManagerCPP
    src/main.cpp
    src/router.cpp
    src/server.cpp
    src/database.cpp
    src/task.cpp
)

# Include directories
target_include_directories(TaskManagerCPP PRIVATE
    src
    include
    ${Boost_INCLUDE_DIRS}
)

# Link libraries
target_link_libraries(TaskManagerCPP PRIVATE
    Boost::system
    Boost::thread
    Boost::beast
    SQLite::SQLite3
)

# -----------------------------
# Tests
# -----------------------------
add_executable(TaskManagerTests
    tests/test_tasks.cpp
    src/task.cpp
)

# Include directories for tests
target_include_directories(TaskManagerTests PRIVATE
    src
    include
)

# Catch2 v3: main come from Catch2::Catch2WithMain
target_link_libraries(TaskManagerTests PRIVATE
    Catch2::Catch2WithMain
)
