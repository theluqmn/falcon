#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <string>

using namespace std;

string getPassword(
    string accountType,
    int accountID
);

int accountExists(
    string accountType,
    int accountID
);

int openAccount(
    string accountType,
    string accountName,
    string accountPassword
);

int closeAccount(
    string accountType,
    int accountID,
    string accountPassword
);

#endif