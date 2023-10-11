#pragma once
#include "crow.h"
#include "user_controller.hpp"

namespace user_todo_app {

    class Server {
    public:
        Server(int port);

        void run();

    private:
        crow::SimpleApp app;
        UserController userController;
    };

} // namespace user_todo_app
