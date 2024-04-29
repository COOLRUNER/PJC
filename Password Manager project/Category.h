#ifndef CATEGORY_H
#define CATEGORY_H

#include "Password.h"
#include <vector>

class Category {
    std::string name;
    std::vector<Password> passwords;

public:
    explicit Category(std::string name);

    std::string getName() const;
    std::vector<Password> getPasswords();

    void addPassword(Password password);
};

#endif
