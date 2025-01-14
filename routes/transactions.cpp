#include <iostream>
#include "routes.h"

using namespace std;

void setupTrasactionsRoutes(crow::SimpleApp& app) {
    CROW_ROUTE(app, "/transactions").methods(crow::HTTPMethod::GET)([](){
        cout << "GET '/transactions' route called" << endl;
        return crow::response(200, "GET '/transactions' route called");
    });
}
