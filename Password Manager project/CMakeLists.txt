cmake_minimum_required(VERSION 3.24)
project(untitled4)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled4 main.cpp Password.cpp Password.h Category.cpp Category.h PasswordController.cpp PasswordController.h CategoryController.cpp CategoryController.h FileService.cpp FileService.h)
