#pragma once

#include <string>

namespace user_todo_app {

    class User {
    public:
        User() = default;
        User(const std::string& name, const std::string& email, const std::string& password, const std::string& address);

        // Getters and setters for user fields
        const std::string& getName() const;
        void setName(const std::string& name);

        const std::string& getEmail() const;
        void setEmail(const std::string& email);

        const std::string& getPassword() const;
        void setPassword(const std::string& password);

        const std::string& getAddress() const;
        void setAddress(const std::string& address);

    private:
        std::string name;
        std::string email;
        std::string password;
        std::string address;
    };

} // namespace user_todo_app
