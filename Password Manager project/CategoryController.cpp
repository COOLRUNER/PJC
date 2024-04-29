#include "CategoryController.h"

using namespace std;

/**
 * @brief Constructs a CategoryController object.
 *
 * @param passwordController A pointer to the PasswordController.
 */
CategoryController::CategoryController(PasswordController* passwordController)
        : passwordController(passwordController) {}

/**
 * @brief Retrieves the vector of categories.
 *
 * @return The vector of categories.
 */
const vector<Category>& CategoryController::getCategories() const {
    return categories;
}

/**
 * @brief Adds a category to the controller.
 *
 * @param category The category to add.
 */
void CategoryController::addCategory(Category category) {
    categories.push_back(category);
}

/**
 * @brief Deletes a category and its associated passwords.
 *
 * @param name The name of the category to delete.
 */
void CategoryController::deleteCategory(string name) {
    categories.erase(
            remove_if(categories.begin(), categories.end(),
                      [&](Category& c) { return c.getName() == name; }),
            categories.end());
    passwordController->deletePasswordByCategory(name);
}


