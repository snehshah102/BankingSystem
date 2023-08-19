#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <ctime>

class Transaction {
public:
    enum class Type { DEPOSIT, WITHDRAW };

    Type type;
    time_t timestamp;
    double amount;

    Transaction(Type t, double amt);
};

#endif 