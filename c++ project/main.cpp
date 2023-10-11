#include "src/server/server.hpp"

int main() {
    user_todo_app::Server server(5000);
    server.run();
    return 0;
}
