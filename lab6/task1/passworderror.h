#ifndef PASSWORDERROR_H
#define PASSWORDERROR_H

#include <stdexcept>
#include <string>

class PasswordError : public std::exception {
public:
    virtual const char* what() const noexcept override = 0;
};

class LengthError : public PasswordError {
public:
    const char* what() const noexcept override;
};

class RegisterError : public PasswordError {
public:
    const char* what() const noexcept override;
};

class DigitError : public PasswordError {
public:
    const char* what() const noexcept override;
};

class ForbiddenLetterError : public PasswordError {
public:
    const char* what() const noexcept override;
};

std::string get_password();

#endif // PASSWORDERROR_H