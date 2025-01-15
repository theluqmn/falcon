#include <iostream>
#include "routes.h"

#include "../functions/accounts/accounts.h"

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
        int senderID = stoi(req.url_params.get("sender")) ? stoi(req.url_params.get("sender")) : -1;
        string password = req.url_params.get("password");

        string receiverType = req.url_params.get("receiverType");
        int receiverID = stoi(req.url_params.get("receiver")) ? stoi(req.url_params.get("receiver")) : -1;

        float amount = stof(req.url_params.get("amount"));
        string description = req.url_params.get("description");

        // validate
        if (senderType.empty() || receiverType.empty() || password.empty()) { return crow::response(400, "Missing parameters."); }
        if (senderID == -1 || receiverID == -1) { return crow::response(400, "Invalid sender or receiver ID."); }
        if (senderID == receiverID) { return crow::response(400, "Sender and receiver cannot be the same."); }
        if (amount <= 0) { return crow::response(400, "Amount must be greater than 0."); }

        int senderExists = accountExists(senderType, senderID);
        int receiverExists = accountExists(receiverType, receiverID);
        if (senderExists == -1 || receiverExists == -1) {  return crow::response(500, "Error checking account existence."); }
        if (senderExists == 0 || receiverExists == 0) { return crow::response(400, "Sender/receiver account does not exist."); }
        
        string validatePassword = getPassword(senderType, senderID);
        if (validatePassword != password) { return crow::response(400, "Invalid sender password."); }

        return crow::response(200, "POST '/transactions' route called");
    });
}
