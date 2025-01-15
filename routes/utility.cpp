#include <iostream>
#include "routes.h"

using namespace std;
using namespace crow;

void setupUtilitiesRoutes(SimpleApp& app) {
    // handles the root route
    CROW_ROUTE(app, "/").methods(HTTPMethod::GET)([](){
        cout << "GET '/'route called" << endl;
        return response(200, "You are requesting the root route of the Falcon API.");
    });

    CROW_ROUTE(app, "/").methods(
        HTTPMethod::POST,
        HTTPMethod::PUT,
        HTTPMethod::DELETE)([]{
        cout << "Unsupported method on '/'" << endl;
        return response(405, "You can only perform GET requests on the root route.");  // Return status code 405
    });
};