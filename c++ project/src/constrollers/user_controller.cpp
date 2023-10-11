#include "user_controller.hpp"

namespace user_todo_app {

    UserController::UserController() {
        // Initialize with some dummy data (you should load data from a database)
        users.push_back(User("John Doe", "john@example.com", "password123", "123 Main St"));
        users.push_back(User("Jane Smith", "jane@example.com", "securepass", "456 Elm Rd"));
    }

    User UserController::createUser(const std::string& name, const std::string& email, const std::string& password, const std::string& address) {
        // Check if the user already exists
        for (const User& user : users) {
            if (user.getEmail() == email) {
                // User with the same email already exists
                // You may want to handle this case differently
                return User(); // Returning an empty User
            }
        }

        // Create a new user and add to the collection
        User newUser(name, email, password, address);
        users.push_back(newUser);
        return newUser;
    }

    User UserController::getUserByEmail(const std::string& email) {
        for (const User& user : users) {
            if (user.getEmail() == email) {
                return user;
            }
        }
        return User(); // User not found, return an empty User
    }

    bool UserController::updateUser(const std::string& email, const std::string& name, const std::string& password, const std::string& address) {
        for (User& user : users) {
            if (user.getEmail() == email) {
                // Update the user data
                user.setName(name);
                user.setPassword(password);
                user.setAddress(address);
                return true; // User updated successfully
            }
        }
        return false; // User not found, update failed
    }

    bool UserController::deleteUser(const std::string& email) {
        auto it = std::remove_if(users.begin(), users.end(), [&](const User& user) {
            return user.getEmail() == email;
        });

        if (it != users.end()) {
            users.erase(it, users.end());
            return true; // User deleted successfully
        }
        return false; // User not found, delete failed
    }

} // namespace user_todo_app
