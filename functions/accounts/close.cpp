#include <iostream>
#include <sqlite3.h>
#include <string>

#include "../functions.h"

using namespace std;

int closeAccount(string accountType, int accountID) {
    // open the database
    sqlite3* db = initAccountsDB();
    if (db == nullptr) {
        return -1;
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
    return 0;
}