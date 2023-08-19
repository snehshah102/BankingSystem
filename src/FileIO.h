#ifndef FILEIO_H
#define FILEIO_H

#include <vector>
#include "Account.h"

class FileIO {
public:
    static void saveAccounts(const std::vector<Account>& accounts, const std::string& filename);
    static std::vector<Account> loadAccounts(const std::string& filename);
};

#endif 
