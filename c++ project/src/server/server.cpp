#include "server.hpp"
#include "user_routes.hpp"

namespace user_todo_app {

    Server::Server(int port) : app(), userController() {
        // Initialize user routes
        UserRoutes userRoutes(app, userController);
    }

    void Server::run() {
        app.port(port).multithreaded().run();
    }

} // namespace user_todo_app
