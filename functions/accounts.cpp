#include <iostream>
#include <sqlite3.h>

using namespace std;

sqlite3* initAccountsDB() {
    sqlite3* db;
    int exit = sqlite3_open("./database/accounts.db", &db);
    if (exit != SQLITE_OK) {
        cout << "Error opening database" << endl;
        return nullptr;
    }

    // create tables (if it doesn't exist)
    
}