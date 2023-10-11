#include "user.hpp"

namespace user_todo_app {

    // Constructor
    User::User(const std::string& name, const std::string& email, const std::string& password, const std::string& address)
        : name(name), email(email), password(password), address(address) {}

    // Getter and setter methods
    const std::string& User::getName() const {
        return name;
    }

    void User::setName(const std::string& name) {
        this->name = name;
    }

    const std::string& User::getEmail() const {
        return email;
    }

    void User::setEmail(const std::string& email) {
        this->email = email;
    }

    const std::string& User::getPassword() const {
        return password;
    }

    void User::setPassword(const std::string& password) {
        this->password = password;
    }

    const std::string& User::getAddress() const {
        return address;
    }

    void User::setAddress(const std::string& address) {
        this->address = address;
    }

} // namespace user_todo_app
