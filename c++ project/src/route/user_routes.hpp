#pragma once

#include <crow.h>
#include "user_controller.hpp"

namespace user_todo_app {

    class UserRoutes {
    public:
        UserRoutes(crow::SimpleApp& app, UserController& controller);

    private:
        UserController& userController;
    };

} // namespace user_todo_app
