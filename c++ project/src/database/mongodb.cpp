#include "./mongodb.hpp"
namespace user_todo_app {

     MongoDB::MongoDB() {
        // Initialize the MongoDB client, database, and collection
        mongocxx::instance instance{}; // Required to initialize the MongoDB driver
        // Use your MongoDB connection URL
        client = mongocxx::client{mongocxx::uri{"mongodb+srv://govindgirigoswami1501:Govind1501@cluster0.bzdnedh.mongodb.net/my_db"}};
        db = client["my_db"];
        usersCollection = db["users"];
    }


    bool MongoDB::createUser(const User& user) {
        try {
            // Convert User object to BSON document
            bsoncxx::document::value userDoc = bsoncxx::builder::stream::document{}
                << "name" << user.getName()
                << "email" << user.getEmail()
                << "password" << user.getPassword()
                << "address" << user.getAddress()
                << bsoncxx::builder::stream::finalize;

            // Insert the document into the "users" collection
            usersCollection.insert_one(userDoc.view());
            return true;
        } catch (const std::exception& e) {
            // Handle error (e.g., duplicate email, database connection issue)
            return false;
        }
    }

    User MongoDB::getUserByEmail(const std::string& email) {
        try {
            bsoncxx::stdx::optional<bsoncxx::document::value> userDocOpt = usersCollection.find_one(
                bsoncxx::builder::stream::document{} << "email" << email << bsoncxx::builder::stream::finalize
            );

            if (userDocOpt) {
                bsoncxx::document::view userDoc = userDocOpt->view();
                User user(
                    userDoc["name"].get_utf8().value.to_string(),
                    userDoc["email"].get_utf8().value.to_string(),
                    userDoc["password"].get_utf8().value.to_string(),
                    userDoc["address"].get_utf8().value.to_string()
                );
                return user;
            } else {
                // User not found
                return User();
            }
        } catch (const std::exception& e) {
            // Handle error (e.g., database connection issue)
            return User();
        }
    }

    bool MongoDB::updateUser(const User& user) {
        try {
            bsoncxx::document::value filterDoc = bsoncxx::builder::stream::document{}
                << "email" << user.getEmail()
                << bsoncxx::builder::stream::finalize;

            bsoncxx::document::value updateDoc = bsoncxx::builder::stream::document{}
                << "$set" << bsoncxx::builder::stream::open_document
                << "name" << user.getName()
                << "password" << user.getPassword()
                << "address" << user.getAddress()
                << bsoncxx::builder::stream::close_document
                << bsoncxx::builder::stream::finalize;

            usersCollection.update_one(filterDoc.view(), updateDoc.view());
            return true;
        } catch (const std::exception& e) {
            // Handle error (e.g., user not found, database connection issue)
            return false;
        }
    }

    bool MongoDB::deleteUser(const std::string& email) {
        try {
            usersCollection.delete_one(
                bsoncxx::builder::stream::document{} << "email" << email << bsoncxx::builder::stream::finalize
            );
            return true;
        } catch (const std::exception& e) {
            // Handle error (e.g., user not found, database connection issue)
            return false;
        }
    }

} // namespace user_todo_app
