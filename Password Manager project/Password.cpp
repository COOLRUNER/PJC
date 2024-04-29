#include <string>
#include "Password.h"
/**
    * @brief Constructs a new Password object with the given details.
    *
    * @param name The name of the password.
    * @param password_text The password text.
    * @param category The category of the password.
    * @param website The website associated with the password.
    * @param login The login information for the password.
    */
Password::Password(std::string name, std::string password_text, std::string category, std::string website, std::string login) :
        name(std::move(name)), password_text(std::move(password_text)), category(std::move(category)), website(std::move(website)), login(std::move(login)) {}

std::string Password::getName() const { return name; }
std::string Password::getPasswordText() const { return password_text; }
std::string Password::getCategory() const { return category; }
std::string Password::getWebsite() const { return website; }
std::string Password::getLogin() const { return login; }

void Password::setName(const std::string& name) {
    Password::name = name;
}

void Password::setPasswordText(const std::string& passwordText) {
    password_text = passwordText;
}

void Password::setCategory(const std::string& category) {
    Password::category = category;
}

void Password::setWebsite(const std::string& website) {
    Password::website = website;
}

void Password::setLogin(const std::string& login) {
    Password::login = login;
}
