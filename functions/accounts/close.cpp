#include <iostream>
#include <sqlite3.h>
#include <string>

#include "../functions.h"
#include "accounts.h"

using namespace std;

int closeAccount(string accountType, int accountID) {
    // open the database
    sqlite3* db = initAccountsDB();
    if (db == nullptr) {
        return -1;
    }

    // check if account exists
    int exists = accountExists(accountType, accountID);
    if (exists == -1) {
        cerr << "Error checking if account exists: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return -1;
    }

    if (exists == 0) {
        sqlite3_close(db);
        return 0;
    }

    // delete account from the database
    string sql = "DELETE FROM " + accountType + " WHERE id = " + to_string(accountID);
    int res = sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);
    if (res != SQLITE_OK) {
        cerr << "Error deleting account: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return -1;
    }

    sqlite3_close(db);
    return 1;
}