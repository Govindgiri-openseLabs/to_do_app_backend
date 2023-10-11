#pragma once

#include <mongocxx/client.hpp>
#include "user.hpp"

namespace user_todo_app {

    class MongoDB {
    public:
        MongoDB();

        // Create a new user in the database
        bool createUser(const User& user);

        // Retrieve a user by email
        User getUserByEmail(const std::string& email);

        // Update user data in the database
        bool updateUser(const User& user);

        // Delete a user by email
        bool deleteUser(const std::string& email);

    private:
        mongocxx::client client;
        mongocxx::database db;
        mongocxx::collection usersCollection;
    };

} // namespace user_todo_app
