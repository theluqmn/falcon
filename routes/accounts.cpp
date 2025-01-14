#include <iostream>
#include "routes.h"
#include "../functions/accounts/accounts.h"

using namespace std;

void setupAccountsRoutes(crow::SimpleApp& app) {
    CROW_ROUTE(app, "/accounts").methods(crow::HTTPMethod::GET)([](){
        cout << "GET '/accounts' route called" << endl;
        return crow::response(200, "Accounts.");
    });

    CROW_ROUTE(app, "/accounts").methods(crow::HTTPMethod::POST)([](const crow::request& req){
        cout << "POST '/accounts' route called" << endl;

        // Accessing query parameters from the request object
        string type = req.url_params.get("type") ? req.url_params.get("type") : "";
        string name = req.url_params.get("name") ? req.url_params.get("name") : "";
        string password = req.url_params.get("password") ? req.url_params.get("password") : "";
        
        // Validate parameters
        if (type.empty()) type = "savings"; // Default value for type
        if (name.empty() || password.empty()) {
            return crow::response(400, "Missing parameters.");
        }

        int open = openAccount(type, name, password);
        if (open == -1) {
            return crow::response(500, "Error opening account.");
        }
        
        return crow::response(200, "Account opened with ID: " + to_string(open));
    });
};
