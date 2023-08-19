#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "Account.h"
#include "User.h"

class Transaction {
public:
    enum class Type { DEPOSIT, WITHDRAW };

    Type type;
    time_t timestamp;
    double amount;

    Transaction(Type t, double amt) : type(t), timestamp(time(nullptr)), amount(amt) {}
};

class Account {
private:
    int accountNumber;
    std::string accountHolder;
    double balance;
    std::vector<Transaction> transactionHistory;

public:
    Account(int number, const std::string& holder) : accountNumber(number), accountHolder(holder), balance(0.0) {}

    int getAccountNumber() const {
        return accountNumber;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            transactionHistory.emplace_back(Transaction::Type::DEPOSIT, amount);
            std::cout << "Deposited $" << amount << " into account #" << accountNumber << std::endl;
        } else {
            std::cout << "Invalid deposit amount." << std::endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            transactionHistory.emplace_back(Transaction::Type::WITHDRAW, amount);
            std::cout << "Withdrawn $" << amount << " from account #" << accountNumber << std::endl;
        } else {
            std::cout << "Insufficient balance or invalid withdrawal amount." << std::endl;
        }
    }

    void displayDetails() const {
        std::cout << "Account #" << accountNumber << " (" << accountHolder << "): $" << balance << std::endl;
    }

    void displayTransactionHistory() const {
        std::cout << "Transaction history for account #" << accountNumber << ":" << std::endl;
        for (const Transaction& transaction : transactionHistory) {
            const std::string typeStr = (transaction.type == Transaction::Type::DEPOSIT) ? "Deposit" : "Withdrawal";
            std::cout << "  " << typeStr << " of $" << transaction.amount << " at " << asctime(localtime(&transaction.timestamp));
        }
    }

    void addInterest(double rate) {
        double interest = balance * rate;
        balance += interest;
        transactionHistory.emplace_back(Transaction::Type::DEPOSIT, interest);
        std::cout << "Interest of $" << interest << " added to account #" << accountNumber << std::endl;
    }
};

int main() {
    std::vector<Account> accounts;
    //Create a user
    User user("admin", "password");

    // Create initial accounts
    accounts.push_back(Account(1001, "Alice"));
    accounts.push_back(Account(1002, "Bob"));

    while (true) {
        int choice;
        std::cout << "Menu:\n1. Deposit\n2. Withdraw\n3. Display Account Details\n4. Display Transaction History\n5. Add Interest\n6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 6) {
            std::cout << "Exiting the banking system.\n";
            break;
        }

        int accountNumber;
        std::cout << "Enter account number: ";
        std::cin >> accountNumber;

        bool accountFound = false;
        for (Account& account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                accountFound = true;

                switch (choice) {
                    case 1: // Deposit
                        double depositAmount;
                        std::cout << "Enter deposit amount: ";
                        std::cin >> depositAmount;
                        account.deposit(depositAmount);
                        break;

                    case 2: // Withdraw
                        double withdrawAmount;
                        std::cout << "Enter withdrawal amount: ";
                        std::cin >> withdrawAmount;
                        account.withdraw(withdrawAmount);
                        break;

                    case 3: // Display Account Details
                        account.displayDetails();
                        break;

                    case 4: // Display Transaction History
                        account.displayTransactionHistory();
                        break;

                    case 5: // Add Interest
                        double interestRate;
                        std::cout << "Enter interest rate: ";
                        std::cin >> interestRate;
                        account.addInterest(interestRate);
                        break;

                    default:
                        std::cout << "Invalid choice.\n";
                        break;
                }

                break; // Exit loop once account is found
            }
        }

        if (!accountFound) {
            std::cout << "Account not found.\n";
        }
    }

    return 0;
}