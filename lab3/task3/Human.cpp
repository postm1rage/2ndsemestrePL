#include "Human.h"
#include <sstream>

Human::Human() : firstName("Unknown"), lastName("Unknown"), patronymic("Unknown") {}

Human::Human(const std::string& firstName, const std::string& lastName, const std::string& patronymic)
    : firstName(firstName), lastName(lastName), patronymic(patronymic) {}

std::string Human::getSurnameAndInitials() const {
    std::stringstream ss;
    ss << lastName << " ";
    if (!firstName.empty()) ss << firstName[0] << ".";
    if (!patronymic.empty()) ss << patronymic[0] << ".";
    return ss.str();
}

std::string Human::getFullName() const {
    return lastName + " " + firstName + " " + patronymic;
}