#include <iostream>
#include <sqlite3.h>
#include <string>

#include "../functions.h"

using namespace std;

int openAccount(string accountType, string accountName, string accountPassword) {
    // validate if account type is valid
    if (accountType != "savings") {
        cerr << "Invalid account type" << endl;
        return -1;
    }

    // open the database
    sqlite3* db = initAccountsDB();
    if (db == nullptr) { return -1; }

    // generate account id
    int accountID = rand() % 90000000 + 10000000;

    // insert account into the database
    string sql = "INSERT INTO " + accountType + " (id, balance, name, password) VALUES (" + to_string(accountID) + ", 10.00, '" + accountName + "', '" + accountPassword + "')";
    int res = sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);
    if (res != SQLITE_OK) {
        cerr << "Error inserting account: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return -1;
    }

    sqlite3_close(db);
    return accountID;
}