#include "vector_operations.h"
#include <iostream>

int main() {
    // Чтение данных
    std::vector<int> numbers = ReadNumbersFromFile("input.txt");
    std::cout << "Vector: ";
    PrintVector(numbers);

    // a) Поиск числа
    int n;
    std::cout << "Type number n: ";
    std::cin >> n;
    FindNumberOccurrences(numbers, n);

    // b) Анализ четных чисел
    AnalyzeEvenNumbers(numbers);

    // c) Сортировка
    SortAndPrint(numbers);

    // d) Обмен элементов
    SwapFirstAndLast(numbers);

    return 0;
}