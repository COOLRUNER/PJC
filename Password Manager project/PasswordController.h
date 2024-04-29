#ifndef PASSWORDCONTROLLER_H
#define PASSWORDCONTROLLER_H

#include "Password.h"
#include <vector>

class PasswordController {
    std::vector<Password> passwords;

public:
    void addPassword(Password password);
    void deletePasswordByCategory(const std::string &categoryName);
    std::string serializeData() const;
    void deletePassword(std::string name);
    void editPassword(std::string oldName, std::string newName);
    Password searchPassword(std::string name);
    void sortPasswords();
    const std::vector<Password> &getPasswords() const;

    void editPassword(const std::string &oldName, const std::string &newName, const std::string &newPasswordText,
                      const std::string &newCategory, const std::string &newWebsite, const std::string &newLogin);
};

#endif