#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string username;
    std::string password;

public:
    User(const std::string& uname, const std::string& pword);

    const std::string& getUsername() const;
    bool authenticate(const std::string& inputPassword) const;
};

#endif 
