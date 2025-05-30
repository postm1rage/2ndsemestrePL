#include "CommonLetters.h"
#include <algorithm>
#include <iterator>

std::string FindCommonLetters(const std::vector<std::string>& words) {
    if (words.empty()) return "";

    // Множество букв первого слова
    std::set<char> common_letters(words[0].begin(), words[0].end());

    for (size_t i = 1; i < words.size(); ++i) {
        std::set<char> current_letters(words[i].begin(), words[i].end());
        std::set<char> temp_intersection;

        // Находим пересечение common_letters и current_letters
        std::set_intersection(
            common_letters.begin(), common_letters.end(),
            current_letters.begin(), current_letters.end(),
            std::inserter(temp_intersection, temp_intersection.begin())
        );

        common_letters = temp_intersection;
        if (common_letters.empty()) break; // Нет общих букв — дальше проверять бессмысленно
    }

    return std::string(common_letters.begin(), common_letters.end());
}