#include "array_utils.h"
#include <iostream>
#include <string>

int main() {
    // Пример 1: Массив целых чисел (int)
    int intArray[] = {10, 20, 30, 40, 50};
    size_t intSize = sizeof(intArray) / sizeof(intArray[0]);
    int targetInt = 30;
    std::cout << "Is number " << targetInt << " contains in array? " 
              << (contains(targetInt, intArray, intSize) ? "Yes" : "No") << std::endl;

    // Пример 2: Массив чисел с плавающей точкой (double)
    double doubleArray[] = {1.5, 2.7, 3.14, 5.0};
    size_t doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);
    double targetDouble = 2.71;
    std::cout << "Is number " << targetDouble << " contains in array? " 
              << (contains(targetDouble, doubleArray, doubleSize) ? "Yes" : "No") << std::endl;

    // Пример 3: Массив строк (std::string)
    std::string stringArray[] = {"apple", "banana", "orange"};
    size_t stringSize = sizeof(stringArray) / sizeof(stringArray[0]);
    std::string targetString = "banana";
    std::cout << "Is \"" << targetString << "\" in array? " 
              << (contains(targetString, stringArray, stringSize) ? "Yes" : "No") << std::endl;

    return 0;
}