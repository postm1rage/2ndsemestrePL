#include "Duplicate.h"
#include <iostream>
#include <vector>

int main() {
    // Тест 1: Целые числа
    std::vector<int> numbers = {1, 2, 3};
    Duplicate(numbers);
    std::cout << "Test 1: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";  // Ожидаемый вывод: 1 2 3 1 2 3

    // Тест 2: Строки
    std::vector<std::string> words = {"Hello", "World"};
    Duplicate(words);
    std::cout << "Test 2: ";
    for (const auto& word : words) {
        std::cout << word << " ";
    }
    std::cout << "\n";  // Ожидаемый вывод: Hello World Hello World

    return 0;
}