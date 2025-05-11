#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class InvalidWeaponException : public std::runtime_error {
public:
    InvalidWeaponException(const std::string& msg) : std::runtime_error(msg) {}
};

class CharacterDeadException : public std::runtime_error {
public:
    CharacterDeadException(const std::string& msg) : std::runtime_error(msg) {}
};

#endif // EXCEPTIONS_H