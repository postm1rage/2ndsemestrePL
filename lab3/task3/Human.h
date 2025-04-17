#pragma once
#include <string>

class Human {
protected:
    std::string firstName;
    std::string lastName;
    std::string patronymic;

public:
    Human();
    Human(const std::string& firstName, const std::string& lastName, const std::string& patronymic);
    
    std::string getSurnameAndInitials() const;
    std::string getFullName() const;
};