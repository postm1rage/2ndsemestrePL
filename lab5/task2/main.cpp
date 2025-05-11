#include "array_utils.h"
#include <iostream>
#include <string>

int main() {
    size_t intSize = 5;
    int* intArray = new int[intSize] {10, 20, 30, 40, 50};
    std::cout << "Array before swap: ";
    printArray(intArray, intSize);
    change(20, 40, intArray, intSize);
    std::cout << "Array after swap: ";
    printArray(intArray, intSize);
    change(20, 99, intArray, intSize);
    delete[] intArray;

    size_t doubleSize = 4;
    double* doubleArray = new double[doubleSize] {1.5, 2.7, 3.14, 5.0};
    std::cout << "\nArray before swap: ";
    printArray(doubleArray, doubleSize);
    change(2.7, 5.0, doubleArray, doubleSize);
    std::cout << "Array after swap: ";
    printArray(doubleArray, doubleSize);
    delete[] doubleArray;

    size_t stringSize = 3;
    std::string* stringArray = new std::string[stringSize] {"apple", "banana", "orange"};
    std::cout << "\nArray before swap: ";
    printArray(stringArray, stringSize);
    
    change(std::string("banana"), std::string("orange"), stringArray, stringSize);
    
    std::cout << "Array after swap: ";
    printArray(stringArray, stringSize);
    delete[] stringArray;

    return 0;
}