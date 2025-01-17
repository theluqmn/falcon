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
    sqlite3* db = initTransactionsDB();
    if (db == nullptr) { return -1; }

    // generate transaction id
    int transactionID = rand() % 90000000 + 10000000;

}