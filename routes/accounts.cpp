#include <iostream>
#include "routes.h"

#include "../functions/accounts/accounts.h"

using namespace std;

void setupAccountsRoutes(crow::SimpleApp& app) {
    CROW_ROUTE(app, "/accounts").methods(crow::HTTPMethod::GET)([](){
        std::cout << "GET '/accounts' route called" << endl;
        return crow::response(200, "Accounts.");
    });

    CROW_ROUTE(app, "/accounts").methods(crow::HTTPMethod::POST)([](){
        std::cout << "POST '/accounts' route called" << endl;
        int open = openAccount("savings", "Luqman", "password");
        if (open == -1) {
            return crow::response(500, "Error opening account.");
        }
        
        return crow::response(200, "Account opened with ID: " + to_string(open));
    });
};