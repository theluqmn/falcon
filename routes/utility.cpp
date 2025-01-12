#include <iostream>
#include "routes.h"

using namespace std;

void setupRoutes(crow::SimpleApp& app) {
    CROW_ROUTE(app, "/").methods(crow::HTTPMethod::GET)([](){
        std::cout << "GET '/'route called" << endl;
        return crow::response(200, "Falcon API.");
    });

    CROW_ROUTE(app, "/").methods(
        crow::HTTPMethod::POST,
        crow::HTTPMethod::PUT,
        crow::HTTPMethod::DELETE)([]{
        std::cout << "Unsupported method on '/'" << endl;
        return crow::response(405, "You can only perform GET requests on the root route.");  // Return status code 405
    });
};