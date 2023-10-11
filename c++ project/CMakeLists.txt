cmake_minimum_required(VERSION 3.10)

project(UserTodoApp)

set(CMAKE_CXX_STANDARD 14)

add_executable(c++ project main.cpp src/routes/user_routes.cpp src/models/user.cpp src/controllers/user_controller.cpp src/database/mongodb.cpp src/server/server.cpp)

find_package(Threads REQUIRED)
target_link_libraries(c++ project Threads::Threads)

# Include the MongoDB C++ driver library (replace with the actual path)
target_link_libraries(c++ project /path/to/mongocxx/libmongocxx.a)
target_link_libraries(c++ project /path/to/bsoncxx/libbsoncxx.a)


# Specify include directories for MongoDB C++ driver and Crow
target_include_directories(c++ project PRIVATE /path/to/mongocxx /path/to/bsoncxx /path/to/crow)


# Specify include directories for MongoDB C++ driver
target_include_directories(c++ project PRIVATE /path/to/mongocxx/include /path/to/bsoncxx/include)

