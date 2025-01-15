#include <iostream>
#include "routes.h"

using namespace std;

void setupTransactionsRoutes(crow::SimpleApp& app) {
    CROW_ROUTE(app, "/transactions").methods(crow::HTTPMethod::GET)([](){
        cout << "GET '/transactions' route called" << endl;
        return crow::response(200, "GET '/transactions' route called");
    });

    CROW_ROUTE(app, "/transactions").methods(crow::HTTPMethod::POST)([](const crow::request& req){
        cout << "POST '/transactions' route called" << endl;

        // params
        string senderType = req.url_params.get("senderType");
        int senderID = stoi(req.url_params.get("sender"));
        string password = req.url_params.get("password");

        string receiverType = req.url_params.get("receiverType");
        int receiverID = stoi(req.url_params.get("receiver"));

        float amount = stof(req.url_params.get("amount"));
        string description = req.url_params.get("description");

        // validate
        if (senderType.empty() || receiverType.empty() || password.empty() || description.empty()) {
            return crow::response(400, "Missing parameters.");
        }
        if (senderID == receiverID) {
            return crow::response(400, "Sender and receiver cannot be the same.");
        }
        if (amount <= 0) {
            return crow::response(400, "Amount must be greater than 0.");
        }
        if (senderType != "savings" && senderType != "checking") {
            return crow::response(400, "Invalid sender type.");
        }

        return crow::response(200, "POST '/transactions' route called");
    });
}
