#include <iostream>
#include <sqlite3.h>

#include "../functions.h"

using namespace std;

string getPassword(string accountType, int accountID) {
    // open the database
    sqlite3* db = initAccountsDB();
    if (db == nullptr) {
        return "";
    }

    // get password from the database
    string sql = "SELECT password FROM " + accountType + " WHERE id = " + to_string(accountID);
    sqlite3_stmt* stmt;
    int res = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);
    if (res != SQLITE_OK) {
        cerr << "Error preparing statement: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return "";
    }

    res = sqlite3_step(stmt);
    if (res != SQLITE_ROW) {
        cerr << "Error getting password: " << sqlite3_errmsg(db) << endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return "";
    }

    string password = (char*)sqlite3_column_text(stmt, 0);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return password;
}
