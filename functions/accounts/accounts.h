#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <string>

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