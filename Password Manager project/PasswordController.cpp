#include <sstream>
#include "PasswordController.h"

/**
 * @brief Adds a password to the controller.
 *
 * @param password The password to add.
 */

void PasswordController::addPassword(Password password) {
    passwords.push_back(password);
}

/**
 * @brief Deletes passwords by category.
 *
 * @param categoryName The category name of the passwords to delete.
 */

void PasswordController::deletePasswordByCategory(const std::string& categoryName) {
    passwords.erase(
            std::remove_if(passwords.begin(), passwords.end(),
                           [&](Password p) { return p.getCategory() == categoryName; }),
            passwords.end());
}

/**
 * @brief Serializes the password data into a string.
 *
 * @return The serialized password data.
 */
std::string PasswordController::serializeData() const {
    std::ostringstream oss;

    for (Password password : passwords) {
        oss << password.getName() << ',' << password.getPasswordText() << ',' << password.getCategory() << ','
            << password.getWebsite() << ',' << password.getLogin() << '\n';
    }

    return oss.str();
}

/**
 * @brief Deletes a password by name.
 *
 * @param name The name of the password to delete.
 */

void PasswordController::deletePassword(std::string name) {
    passwords.erase(std::remove_if(passwords.begin(), passwords.end(),
                                   [&](Password p) { return p.getName() == name; }),
                    passwords.end());
}

/**
 * @brief Edits a password with new information.
 *
 * @param oldName The current name of the password.
 * @param newName The new name of the password.
 * @param newPasswordText The new password text.
 * @param newCategory The new category of the password.
 * @param newWebsite The new website of the password.
 * @param newLogin The new login information of the password.
 */

void PasswordController::editPassword(const std::string& oldName, const std::string& newName,
                                      const std::string& newPasswordText, const std::string& newCategory,
                                      const std::string& newWebsite, const std::string& newLogin) {
    for (auto& password : passwords) {
        if (password.getName() == oldName) {
            password.setName(newName);
            password.setPasswordText(newPasswordText);
            password.setCategory(newCategory);
            password.setWebsite(newWebsite);
            password.setLogin(newLogin);
            break;
        }
    }
}


/**
 * @brief Searches for a password by name.
 *
 * @param name The name of the password to search for.
 * @return The found password, or an empty password if not found.
 */

Password PasswordController::searchPassword(std::string name) {
    for (auto& password : passwords) {
        if (password.getName() == name) {
            return password;
        }
    }
    return Password("", "", "");
}


/**
 * @brief Sorts the passwords in ascending order by name.
 */
void PasswordController::sortPasswords() {
    std::sort(passwords.begin(), passwords.end(),
              [](Password a, Password b) {
                  return a.getName() < b.getName();
              });
}

const std::vector<Password>& PasswordController::getPasswords() const {
    return passwords;
}
