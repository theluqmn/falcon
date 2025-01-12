#include <iostream>
#include "routes.h"

using namespace std;

void setupAccountsRoutes(crow::SimpleApp& app) {
    CROW_ROUTE(app, "/accounts").methods(crow::HTTPMethod::GET)([](){
        std::cout << "GET '/accounts' route called" << endl;
        return crow::response(200, "Accounts.");
    });
};