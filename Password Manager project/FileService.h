#ifndef FILESERVICE_H
#define FILESERVICE_H

#include <string>

class FileService {
    std::string filePath;
    std::string password;

public:
    explicit FileService(std::string filePath);

    std::string readFile();
    void writeFile(std::string content);
    std::string encrypt(const std::string& text, const std::string& password);
    std::string decrypt(const std::string& text, const std::string& password);
    void setPassword(const std::string& enteredPassword);
};

#endif
