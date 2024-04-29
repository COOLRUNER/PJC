

#ifndef PASSWORD_H
#define PASSWORD_H

#include <string>

class Password {
    std::string name;
    std::string password_text;
    std::string category;
    std::string website;
    std::string login;

public:
    Password(std::string name, std::string password_text, std::string category, std::string website = "", std::string login = "");

    std::string getName() const;
    std::string getPasswordText() const;
    std::string getCategory() const;
    std::string getWebsite() const;
    std::string getLogin() const;

    void setName(const std::string &name);
    void setPasswordText(const std::string &passwordText);
    void setCategory(const std::string &category);
    void setWebsite(const std::string &website);
    void setLogin(const std::string &login);
};

#endif
