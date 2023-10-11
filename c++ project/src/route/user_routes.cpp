#include "user_routes.hpp"
#include <crow.h>

namespace user_todo_app {

    UserRoutes::UserRoutes(crow::SimpleApp& app, UserController& controller) : userController(controller) {
        // Create a new user
        CROW_ROUTE(app, "/users/create").methods(crow::HTTPMethod::POST)
        ([&](const crow::request& req) {
            crow::json::wvalue response;

            // Parse JSON data from the request
            auto json = crow::json::load(req.body);

            if (!json) {
                response["status"] = "error";
                response["message"] = "Invalid JSON data";
                return crow::response(400, response);
            }

            const std::string name = json["name"].s();
            const std::string email = json["email"].s();
            const std::string password = json["password"].s();
            const std::string address = json["address"].s();

            // Create the user
            User newUser = userController.createUser(name, email, password, address);

            if (newUser.getEmail().empty()) {
                response["status"] = "error";
                response["message"] = "User with the same email already exists";
                return crow::response(409, response);
            }

            response["status"] = "success";
            response["message"] = "User created successfully";
            response["user"] = newUser;
            return crow::response(201, response);
        });

        // Retrieve a user by email
        CROW_ROUTE(app, "/users/<string>").methods(crow::HTTPMethod::GET)
        ([&](const crow::request& req, std::string email) {
            crow::json::wvalue response;
            User user = userController.getUserByEmail(email);

            if (user.getEmail().empty()) {
                response["status"] = "error";
                response["message"] = "User not found";
                return crow::response(404, response);
            }

            response["status"] = "success";
            response["user"] = user;
            return crow::response(200, response);
        });

        // Update user data
        CROW_ROUTE(app, "/users/<string>").methods(crow::HTTPMethod::PUT)
        ([&](const crow::request& req, std::string email) {
            crow::json::wvalue response;

            // Parse JSON data from the request
            auto json = crow::json::load(req.body);

            if (!json) {
                response["status"] = "error";
                response["message"] = "Invalid JSON data";
                return crow::response(400, response);
            }

            const std::string name = json["name"].s();
            const std::string password = json["password"].s();
            const std::string address = json["address"].s();

            if (userController.updateUser(email, name, password, address)) {
                response["status"] = "success";
                response["message"] = "User updated successfully";
                return crow::response(204, response);
            } else {
                response["status"] = "error";
                response["message"] = "User not found";
                return crow::response(404, response);
            }
        });

        // Delete a user by email
        CROW_ROUTE(app, "/users/<string>").methods(crow::HTTPMethod::DEL)
        ([&](const crow::request& req, std::string email) {
            crow::json::wvalue response;

            if (userController.deleteUser(email)) {
                response["status"] = "success";
                response["message"] = "User deleted successfully";
                return crow::response(204, response);
            } else {
                response["status"] = "error";
                response["message"] = "User not found";
                return crow::response(404, response);
            }
        });
    }

} // namespace user_todo_app
