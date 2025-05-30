#include "WordCounter.h"
#include <iostream>
#include <unordered_map>

void CountWordOccurrences() {
    std::unordered_map<std::string, int> word_counts;
    std::string word;

    while (std::cin >> word) {
        std::cout << ++word_counts[word] << "\n";
    }
}