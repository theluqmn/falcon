#include <iostream>
#include <string>
#include "crow_all.h"

#include "routes/routes.h"

using namespace std;
using namespace crow;

int main()
{
    cout << "FALCON\nhttps://github.com/theluqmn/falcon\n----" << endl;
    
    // create the crow app and setup all the routes
    SimpleApp app;
    setupAccountsRoutes(app);
    setupUtilitiesRoutes(app);

    app.loglevel(LogLevel::Warning);

    // run the app
    app.port(6969).multithreaded().run();
}