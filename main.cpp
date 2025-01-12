#include <iostream>
#include <string>
#include "crow_all.h"

using namespace std;

int main()
{
    crow::SimpleApp app; //define your crow application
    std::cout << "Hello World!" << std::endl;

    //define your endpoint at the root directory
    CROW_ROUTE(app, "/")([](){
        return "Hello world";
    });

    app.loglevel(crow::LogLevel::Warning);

    //set the port, set the app to run on multiple threads, and run the app
    app.port(18080).multithreaded().run();
}