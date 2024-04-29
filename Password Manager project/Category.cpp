#include <string>
#include <vector>
#include "Category.h"

/**
 * @brief The Category class represents a category in the password manager.
 *
 * This class stores information about a category, including its name and the passwords associated with it.
 * It provides methods to access and modify the category details.
 */

Category::Category(std::string name) : name(name) {}

std::string Category::getName() const { return name; }

std::vector<Password> Category::getPasswords() { return passwords; }

/**
 * @brief Adds a password to the category.
 *
 * @param password The Password object to add.
 */

void Category::addPassword(Password password) {
    passwords.push_back(password);
}
