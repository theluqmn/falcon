#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include <string>

using namespace std;

int newTransaction(
    string senderType,
    int senderID,
    string receiverType,
    int receiverID,
    float amount,
    string description
);

#endif