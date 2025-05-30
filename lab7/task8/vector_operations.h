#pragma once
#include <vector>
#include <string>

// Чтение данных из файла в вектор
std::vector<int> ReadNumbersFromFile(const std::string& filename);

// a) Поиск числа n и его позиций
void FindNumberOccurrences(const std::vector<int>& numbers, int n);

// b) Анализ четных элементов и сумм
void AnalyzeEvenNumbers(const std::vector<int>& numbers);

// c) Сортировка и вывод
void SortAndPrint(std::vector<int> numbers);

// d) Обмен первого и последнего элемента
void SwapFirstAndLast(std::vector<int>& numbers);

// Вспомогательная функция для печати вектора
void PrintVector(const std::vector<int>& v);