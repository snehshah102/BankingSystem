#include "Transaction.h"

Transaction::Transaction(Type t, double amt) : type(t), timestamp(time(nullptr)), amount(amt) {}
