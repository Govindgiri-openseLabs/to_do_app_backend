#pragma once

#include "user.hpp"
#include <vector>
#include <string>

namespace user_todo_app {

    class UserController {
    public:
        UserController();

        // Create a new user
        User createUser(const std::string& name, const std::string& email, const std::string& password, const std::string& address);

        // Retrieve a user by email
        User getUserByEmail(const std::string& email);

        // Update user data
        bool updateUser(const std::string& email, const std::string& name, const std::string& password, const std::string& address);

        // Delete a user by email
        bool deleteUser(const std::string& email);

    private:
        std::vector<User> users;
    };

} // namespace user_todo_app
