#include "OddEvenSeparator.h"
#include <iostream>

// Метод для добавления числа
void OddEvenSeparator::add_number(int number) {
    numbers.push_back(number); // Добавляем число в общий список
    if (number % 2 == 0) {
        evens.push_back(number);
    } else {
        odds.push_back(number);
    }
}

// Метод для вывода чётных чисел
void OddEvenSeparator::even() {
    std::cout << "Even numbers: ";
    for (int num : evens) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Метод для вывода нечётных чисел
void OddEvenSeparator::odd() {
    std::cout << "Odd numbers: ";
    for (int num : odds) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}