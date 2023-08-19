#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>
#include "Transaction.h"

class Account {
private:
    int accountNumber;
    std::string accountHolder;
    double balance;
    std::vector<Transaction> transactionHistory;

public:
    Account(int number, const std::string& holder);

    int getAccountNumber() const;
    void deposit(double amount);
    void withdraw(double amount);
    void displayDetails() const;
    void displayTransactionHistory() const;
    void addInterest(double rate);
};

#endif
