#include "PasswordError.h"
#include <string>
#include <cctype> // https://learn.microsoft.com/ru-ru/cpp/standard-library/cctype?view=msvc-170
#include <algorithm>
#include <iostream>

const char* LengthError::what() const noexcept {
    return "Password is too short (less than 9 characters)";
}

const char* RegisterError::what() const noexcept {
    return "Password contains only one case letters";
}

const char* DigitError::what() const noexcept {
    return "Password doesn't contain any digits";
}

const char* ForbiddenLetterError::what() const noexcept {
    return "Password contains forbidden characters (l, I, 1, o, O, 0)";
}

std::string get_password() {
    std::string password;
    std::cout << "Enter password: ";
    std::cin >> password;

    // Check length
    if (password.length() < 9) {
        throw LengthError();
    }

    // Check register
    bool has_upper = false, has_lower = false;
    for (char c : password) {
        if (isupper(c)) has_upper = true;
        if (islower(c)) has_lower = true;
    }
    if (!(has_upper && has_lower)) {
        throw RegisterError();
    }

    // Check digits
    bool has_digit = false;
    for (char c : password) {
        if (isdigit(c)) {
            has_digit = true;
            break;
        }
    }
    if (!has_digit) {
        throw DigitError();
    }

    // Check forbidden characters
    const std::string forbidden = "lI1oO0";
    for (char c : password) {
        if (forbidden.find(c) != std::string::npos) {
            throw ForbiddenLetterError();
        }
    }

    return password;
}