#include "Account.h"
#include <iostream>
#include <ctime>

Account::Account(int number, const std::string& holder) : accountNumber(number), accountHolder(holder), balance(0.0) {}

