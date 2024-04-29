#ifndef CATEGORYCONTROLLER_H
#define CATEGORYCONTROLLER_H

#include "Category.h"
#include "PasswordController.h"
#include <vector>

class CategoryController {
    std::vector<Category> categories;
    PasswordController *passwordController;

public:
    explicit CategoryController(PasswordController *passwordController);

    const std::vector<Category> &getCategories() const;

    void addCategory(Category category);
    void deleteCategory(std::string name);
};

#endif

