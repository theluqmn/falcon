#include <iostream>
#include <string>
#include "crow_all.h"

#include "routes/routes.h"

using namespace std;

int main()
{
    cout << "FALCON\nhttps://github.com/theluqmn/falcon\n----" << endl;
    
    // create the crow app and setup all the routes
    crow::SimpleApp app;
    setupRoutes(app);

    app.loglevel(crow::LogLevel::Warning);

    // run the app
    app.port(6969).multithreaded().run();
}