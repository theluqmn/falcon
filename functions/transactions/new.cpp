#include <iostream>
#include <sqlite3.h>
#include <string>

#include "../accounts/accounts.h"
#include "../functions.h"

using namespace std;

int newTransaction(string senderType, int senderID, string receiverType, int receiverID, float amount, string description) {
    // validate existence of accounts
    int senderExists = accountExists(senderType, senderID);
    int receiverExists = accountExists(receiverType, receiverID);
    if (senderExists == -1 || receiverExists == -1) {  return -1; }
    if (senderExists == 0 || receiverExists == 0) { return -1; }

    // open the database
    sqlite3* transactionsDB = initTransactionsDB();
    if (transactionsDB == nullptr) { return -1; }

    sqlite3* accountsDB = initAccountsDB();
    if (accountsDB == nullptr) { return -1; }

    // perform transaction
    string sql = "UPDATE " + senderType + " SET balance = balance - " + to_string(amount) + " WHERE id = " + to_string(senderID);
    int res = sqlite3_exec(accountsDB, sql.c_str(), NULL, NULL, NULL);
    if (res != SQLITE_OK) {
        cerr << "Error updating account balance: " << sqlite3_errmsg(accountsDB) << endl;
        return -1;
    }

    sql = "UPDATE " + receiverType + " SET balance = balance + " + to_string(amount) + " WHERE id = " + to_string(receiverID);
    res = sqlite3_exec(accountsDB, sql.c_str(), NULL, NULL, NULL);
    if (res != SQLITE_OK) {
        cerr << "Error updating account balance: " << sqlite3_errmsg(accountsDB) << endl;
        return -1;
    }

    // insert transaction into the database
    sql = "INSERT INTO transactions (account_id, amount, description) VALUES (" + to_string(senderID) + ", " + to_string(amount) + ", '" + description + "')";
    res = sqlite3_exec(transactionsDB, sql.c_str(), NULL, NULL, NULL);
    if (res != SQLITE_OK) {
        cerr << "Error inserting transaction: " << sqlite3_errmsg(transactionsDB) << endl;
        sqlite3_close(transactionsDB);
        return -1;
    }

    sqlite3_close(transactionsDB);
    sqlite3_close(accountsDB);
    return 1;
}