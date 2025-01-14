#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <string>

std::string getPassword(
    std::string accountType,
    int accountID
);

int accountExists(
    std::string accountType,
    int accountID
);

int openAccount(
    std::string accountType,
    std::string accountName,
    std::string accountPassword
);

int closeAccount(
    std::string accountType,
    int accountID
);

#endif