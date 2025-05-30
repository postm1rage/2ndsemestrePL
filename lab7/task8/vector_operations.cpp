#include "vector_operations.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>

std::vector<int> ReadNumbersFromFile(const std::string& filename) {
    std::ifstream input(filename);
    std::vector<int> numbers;
    int num;
    while (input >> num) {
        numbers.push_back(num);
    }
    return numbers;
}

void FindNumberOccurrences(const std::vector<int>& numbers, int n) {
    int count = std::count(numbers.begin(), numbers.end(), n);
    std::cout << "The number " << n << " shows up " << count << " time(s).\nPositions: ";
    
    auto it = std::find(numbers.begin(), numbers.end(), n);
    while (it != numbers.end()) {
        std::cout << (it - numbers.begin()) << " ";
        it = std::find(std::next(it), numbers.end(), n);
    }
    std::cout << "\n";
}

void AnalyzeEvenNumbers(const std::vector<int>& numbers) {
    int even_count = std::count_if(numbers.begin(), numbers.end(), [](int x) { return x % 2 == 0; });
    std::cout << "Amount of even elements: " << even_count << "\nNumbers of even elements: ";
    
    for (size_t i = 0; i < numbers.size(); ++i) {
        if (numbers[i] % 2 == 0) {
            std::cout << i << " ";
        }
    }
    
    int sum;
    if (even_count > numbers.size() - even_count) {
        sum = std::accumulate(numbers.begin(), numbers.end(), 0, [](int a, int b) { return b % 2 == 0 ? a + b : a; });
        std::cout << "\nSum of even elements: " << sum << "\n";
    } else {
        sum = std::accumulate(numbers.begin(), numbers.end(), 0);
        std::cout << "\nSum of all elements: " << sum << "\n";
    }
}

void SortAndPrint(std::vector<int> numbers) {
    std::sort(numbers.begin(), numbers.end());
    std::cout << "Sorted vector: ";
    PrintVector(numbers);
}

void SwapFirstAndLast(std::vector<int>& numbers) {
    if (!numbers.empty()) {
        std::swap(numbers.front(), numbers.back());
        std::cout << "The vector after swap: ";
        PrintVector(numbers);
    }
}

void PrintVector(const std::vector<int>& v) {
    for (int num : v) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}