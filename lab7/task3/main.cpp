#include "CommonLetters.h"
#include <iostream>
#include <vector>
#include <sstream>

int main() {
    std::string line;
    std::getline(std::cin, line); // Читаем всю строку
    std::istringstream iss(line);
    std::vector<std::string> words;
    std::string word;

    while (iss >> word) {
        words.push_back(word);
    }

    std::string result = FindCommonLetters(words);
    std::cout << result << std::endl;

    return 0;
}