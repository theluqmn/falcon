#include <iostream>
#include <sqlite3.h>
#include <string>

using namespace std;

sqlite3* initAccountsDB() {
    // open the database
    sqlite3 *db;
    int res = sqlite3_open("database/accounts.db", &db);
    char* zErrMsg = 0;
    sqlite3_exec(db, "PRAGMA foreign_keys = ON;", 0, 0, &zErrMsg);
    sqlite3_exec(db, "PRAGMA journal_mode = WAL;", 0, 0, &zErrMsg);
    if (res != SQLITE_OK) {
        cerr << "Error opening database: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return nullptr;
    };

    // create the savings table
    string savings_table = "CREATE TABLE IF NOT EXISTS savings (id INTEGER PRIMARY KEY, balance FLOAT, name TEXT, password TEXT)";
    res = sqlite3_exec(db, savings_table.c_str(), NULL, NULL, NULL);
    if (res != SQLITE_OK) {
        cerr << "Error creating table: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return nullptr;
    }

    return db;
}

sqlite3* initTransactionsDB() {
    // open the database
    sqlite3 *db;
    int res = sqlite3_open("database/transactions.db", &db);
    char* zErrMsg = 0;
    sqlite3_exec(db, "PRAGMA foreign_keys = ON;", 0, 0, &zErrMsg);
    sqlite3_exec(db, "PRAGMA journal_mode = WAL;", 0, 0, &zErrMsg);
    if (res != SQLITE_OK) {
        cerr << "Error opening database: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return nullptr;
    }

    // create the transactions table
    string transactions_table = "CREATE TABLE IF NOT EXISTS transactions (id INTEGER PRIMARY KEY, account_id INTEGER, amount FLOAT, description TEXT, date TEXT, FOREIGN KEY(account_id) REFERENCES savings(id))";
    res = sqlite3_exec(db, transactions_table.c_str(), NULL, NULL, NULL);
    if (res != SQLITE_OK) {
        cerr << "Error creating table: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return nullptr;
    }

    return db;
}