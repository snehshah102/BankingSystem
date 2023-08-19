#include "User.h"

User::User(const std::string& uname, const std::string& pword) : username(uname), password(pword) {}

const std::string& User::getUsername() const {
    return username;
}

bool User::authenticate(const std::string& inputPassword) const {
    return inputPassword == password;
}
