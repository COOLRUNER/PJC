#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Category.h"
#include "CategoryController.h"
#include "FileService.h"
#include "Password.h"
#include "PasswordController.h"

using namespace std;

/**
 * @brief The main function that runs the password manager program.
 *
 * This function prompts the user to enter a file path and password to access the password data.
 * It reads the data from the file, initializes the controllers, and performs various operations based on user input.
 */

int main() {
    string filePath;
    string password;

    cout << "Enter file path: ";
    getline(cin, filePath);

    cout << "Enter password: ";
    getline(cin, password);

    FileService fileService(filePath);
    fileService.setPassword(password);

    PasswordController passwordController;
    CategoryController categoryController(&passwordController);

    string data = fileService.readFile();


    istringstream iss(data);
    string line;
    while (getline(iss, line)) {

        istringstream lineStream(line);
        string name, password_text, category, website, login;
        getline(lineStream, name, ',');
        getline(lineStream, password_text, ',');
        getline(lineStream, category, ',');
        getline(lineStream, website, ',');
        getline(lineStream, login, ',');

        Password passwordObj = Password(name, password_text, category, website, login);

        passwordController.addPassword(Password(name, password_text, category, website, login));

        bool categoryExists = false;
        for (Category existingCategory : categoryController.getCategories()) {
            if (existingCategory.getName() == category) {
                existingCategory.addPassword(passwordObj);
                categoryExists = true;
                break;
            }
        }

        if (!categoryExists) {
            Category newCategory(category);
            newCategory.addPassword(passwordObj);
            categoryController.addCategory(newCategory);
        }
    }

    cout << "Categories and Passwords at the start of the program:" << endl;
    for (Category category : categoryController.getCategories()) {
        cout << "Category: " << category.getName() << endl;
        const vector<Password>& passwords = category.getPasswords();
        for (const Password& password : passwords) {
            cout << "  Name: " << password.getName() << endl;
            cout << "  Password: " << password.getPasswordText() << endl;
            cout << "  Website: " << password.getWebsite() << endl;
            cout << "  Login: " << password.getLogin() << endl;
            cout << endl;
        }
    }
    std::string choice;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add password\n";
        cout << "2. Delete password\n";
        cout << "3. Edit password\n";
        cout << "4. Search password\n";
        cout << "5. Add category\n";
        cout << "6. Delete category\n";
        cout << "7. Show all passwords\n";
        cout << "8. Sort passwords\n";
        cout << "9. Quit\n";
        cout << "Enter your choice: ";

        getline(cin, choice);

        if (choice.empty()) {
            cout << "Invalid choice. Try again.\n";
            continue;
        }

        int option = stoi(choice);

        switch (option) {
            case 1: {
                string name, password_text, category, website, login;
                cout << "Add Password:\n";
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter password: ";
                getline(cin, password_text);

                cout << "Available Categories:" << endl;
                for (const Category& category : categoryController.getCategories()) {
                    cout << "- " << category.getName() << endl;
                }

                cout << "Choose a category: ";
                getline(cin, category);

                cout << "Enter website: ";
                getline(cin, website);
                cout << "Enter login: ";
                getline(cin, login);

                passwordController.addPassword(Password(name, password_text, category, website, login));
                string serializedData = passwordController.serializeData();
                fileService.writeFile(serializedData);

                cout << "Password added successfully!\n";
                break;
            }
            case 2: {
                string name;
                cout << "Delete Password:\n";
                cout << "Enter name: ";
                getline(cin, name);
                passwordController.deletePassword(name);
                string serializedData = passwordController.serializeData();
                fileService.writeFile(serializedData);

                cout << "Password deleted successfully!\n";
                break;
            }
            case 3: {
                string oldName, newName, newPasswordText, newCategory, newWebsite, newLogin;
                cout << "Edit Password:\n";
                cout << "Enter old name: ";
                getline(cin, oldName);
                cout << "Enter new name: ";
                getline(cin, newName);
                cout << "Enter new password: ";
                getline(cin, newPasswordText);
                cout << "Enter new category: ";
                getline(cin, newCategory);
                cout << "Enter new website: ";
                getline(cin, newWebsite);
                cout << "Enter new login: ";
                getline(cin, newLogin);

                passwordController.editPassword(oldName, newName, newPasswordText, newCategory, newWebsite, newLogin);

                string serializedData = passwordController.serializeData();
                fileService.writeFile(serializedData);

                cout << "Password edited successfully!\n";
                break;
            }

            case 4: {
                string name;
                cout << "Search Password:\n";
                cout << "Enter name: ";
                getline(cin, name);
                Password password = passwordController.searchPassword(name);
                if (password.getName().empty()) {
                    cout << "Password not found!\n";
                } else {
                    cout << "Password Details:\n";
                    cout << "  Name: " << password.getName() << endl;
                    cout << "  Password: " << password.getPasswordText() << endl;
                    cout << "  Website: " << password.getWebsite() << endl;
                    cout << "  Login: " << password.getLogin() << endl;
                }
                break;
            }
            case 5: {
                string name;
                cout << "Add Category:\n";
                cout << "Enter name: ";
                getline(cin, name);
                categoryController.addCategory(Category(name));

                cout << "Category added successfully!\n";
                break;
            }
            case 6: {
                string name;
                cout << "Delete Category:\n";
                cout << "Enter name: ";
                getline(cin, name);
                categoryController.deleteCategory(name);

                cout << "Category deleted successfully!\n";
                break;
            }
            case 7: {
                cout << "All Passwords:\n";
                const auto& passwords = passwordController.getPasswords();
                if (passwords.empty()) {
                    cout << "No passwords found!\n";
                } else {
                    for (const auto& password : passwords) {
                        cout << "Name: " << password.getName() << '\n';
                        cout << "Password: " << password.getPasswordText() << '\n';
                        cout << "Category: " << password.getCategory() << '\n';
                        cout << "Website: " << password.getWebsite() << '\n';
                        cout << "Login: " << password.getLogin() << '\n';
                        cout << "----------------------------\n";
                    }
                }
                break;
            }
            case 8: {
                passwordController.sortPasswords();
                cout << "Passwords sorted successfully!\n";
                break;
            }

            case 9: {
                cout << "Exiting the program. Goodbye!\n";
                return 0;
            }
            default: {
                cout << "Invalid choice. Try again.\n";
                break;
            }
        }
    }

}


