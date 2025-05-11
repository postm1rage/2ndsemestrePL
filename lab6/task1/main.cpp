#include <iostream>
#include "PasswordError.h"

int main() {
    try {
        std::string password = get_password();
        std::cout << "Password accepted: " << password << std::endl;
    }
    catch (const PasswordError& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
    }

    return 0;
}