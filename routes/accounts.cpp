#include <iostream>
#include "routes.h"
#include "../functions/accounts/accounts.h"

using namespace std;

void setupAccountsRoutes(crow::SimpleApp& app) {
    CROW_ROUTE(app, "/accounts").methods(crow::HTTPMethod::GET)([](){
        cout << "GET '/accounts' route called" << endl;
        return crow::response(200, "Get account.");
    });

    // create a new account
    CROW_ROUTE(app, "/accounts").methods(crow::HTTPMethod::POST)([](const crow::request& req){
        cout << "POST '/accounts' route called" << endl;

        // params
        string type = req.url_params.get("type") ? req.url_params.get("type") : "";
        string name = req.url_params.get("name") ? req.url_params.get("name") : "";
        string password = req.url_params.get("password") ? req.url_params.get("password") : "";
        
        // validate
        if (type.empty()) type = "savings";
        if (name.empty() || password.empty()) {
            return crow::response(400, "Missing parameters.");
        }

        // open account
        int open = openAccount(type, name, password);
        if (open == -1) {
            return crow::response(500, "Error opening account.");
        }

        return crow::response(200, "Account opened with ID: " + to_string(open));
    });

    // delete an account
    CROW_ROUTE(app, "/accounts").methods(crow::HTTPMethod::DELETE)([](const crow::request& req){
        cout << "DELETE '/accounts' route called" << endl;

        // params
        string type = req.url_params.get("type") ? req.url_params.get("type") : "savings";
        int id = req.url_params.get("id") ? stoi(req.url_params.get("id")) : -1;
        string password = req.url_params.get("password") ? req.url_params.get("password") : "";

        // validate
        if (id == -1) {
            return crow::response(400, "Missing account ID.");
        }

        // close account
        int close = closeAccount(type, id, password);
        if (close == 0) {
            return crow::response(404, "Account not found.");
        }
        if (close == -1) {
            return crow::response(500, "Error closing account.");
        }
        if (close == -2) {
            return crow::response(401, "Incorrect password.");
        }

        return crow::response(200, "Deleted account: " + to_string(id));
    });
};
