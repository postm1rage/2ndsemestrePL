#include "Unique.h"
#include <iostream>
#include <vector>

int main() {
    // Тест с целыми числами
    std::vector<int> numbers = {1, 1, 2, 3, 3, 4};
    auto new_end = Unique(numbers.begin(), numbers.end());
    for (auto it = numbers.begin(); it != new_end; ++it) {
        std::cout << *it << " ";  // Вывод: 1 2 3 4
    }

    // Тест со строками (отдельно!)
    std::vector<std::string> words = {"a", "a", "b", "c"};
    auto words_end = Unique(words.begin(), words.end());
    for (auto it = words.begin(); it != words_end; ++it) {
        std::cout << *it << " ";  // Вывод: a b c
    }

    return 0;
}