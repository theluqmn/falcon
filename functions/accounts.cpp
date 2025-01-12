#include <iostream>
#include <sqlite3.h>

using namespace std;

sqlite3* initAccountsDB() {
    sqlite3* db;
    int accounts_db = sqlite3_open("./database/accounts.db", &db);
    if (accounts_db != SQLITE_OK) {
        cout << "Error opening database" << endl;
        return nullptr;
    }
}