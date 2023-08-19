#include "FileIO.h"
#include <fstream>
#include <iostream>

void FileIO::saveAccounts(const std::vector<Account>& accounts, const std::string& filename) {
    std::ofstream outFile(filename, std::ios::binary);
    
    if (!outFile) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }
    
    for (const Account& account : accounts) {
        outFile.write(reinterpret_cast<const char*>(&account), sizeof(Account));
    }
    
    outFile.close();
}

std::vector<Account> FileIO::loadAccounts(const std::string& filename) {
    std::vector<Account> accounts;
    std::ifstream inFile(filename, std::ios::binary);
    
    if (!inFile) {
        std::cerr << "Error opening file for reading: " << filename << std::endl;
        return accounts;
    }
    
    inFile.close();
    return accounts;
}