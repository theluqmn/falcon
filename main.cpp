#include <iostream>
#include <string>
#include "crow_all.h"

using namespace std;

int main()
{
    crow::SimpleApp app; //define your crow application
    cout << "FALCON\nhttps://github.com/theluqmn/falcon\n----" << endl;

    CROW_ROUTE(app, "/")([](){
        return "Hello world";
    });

    CROW_ROUTE(app, "/hello").methods(crow::HTTPMethod::GET)([](){
        return "Hello!";
    });

    app.loglevel(crow::LogLevel::Warning);

    //set the port, set the app to run on multiple threads, and run the app
    app.port(18080).multithreaded().run();
}