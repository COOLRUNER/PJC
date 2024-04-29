#include <fstream>
#include <sstream>
#include "FileService.h"

using namespace std;

/**
 * @brief Constructs a FileService object.
 *
 * @param filePath The file path to read from/write to.
 */
FileService::FileService(string filePath)
        : filePath(filePath) {}

/**
 * @brief Reads the content of the file and decrypts it using the password.
 *
 * @return The decrypted content of the file.
 */
string FileService::readFile() {
    ifstream file(filePath);
    stringstream buffer;
    buffer << file.rdbuf();
    string content = buffer.str();
    file.close();
    return decrypt(content, password);
}

/**
 * @brief Encrypts the provided content and writes it to the file.
 *
 * @param content The content to write.
 */
void FileService::writeFile(string content) {
    ofstream file(filePath);
    file << encrypt(content, password);
    file.close();
}

/**
 * @brief Encrypts the provided text using the password.
 *
 * @param text The text to encrypt.
 * @param password The password to use for encryption.
 * @return The encrypted text.
 */
string FileService::encrypt(const string& text, const string& password) {
    string result = text;

    for (size_t i = 0; i < text.size(); ++i) {
        result[i] = text[i] ^ password[i % password.size()];
    }

    return result;
}

/**
 * @brief Decrypts the provided text using the password.
 *
 * @param text The text to decrypt.
 * @param password The password to use for decryption.
 * @return The decrypted text.
 */
string FileService::decrypt(const string& text, const string& password) {
    return encrypt(text, password);
}

/**
 * @brief Sets the password to be used for encryption and decryption.
 *
 * @param enteredPassword The password to set.
 */
void FileService::setPassword(const string& enteredPassword) {
    password = enteredPassword;
}
