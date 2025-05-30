#include "Process.h"
#include <iostream>
#include <vector>

// Реализация PrintResults
template <typename Iter>
void PrintResults(Iter first, Iter last) {
    for (Iter it = first; it != last; ++it)
        std::cout << *it << std::endl;
}

int main() {
    std::vector<int> data = {1, -2, 3, -4, 5};
    Process(data);  // Вывод: 1, 3, 5 (каждое с новой строки)
    return 0;
}