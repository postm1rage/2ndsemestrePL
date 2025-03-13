#include "Candy.h"
#include <iostream>
#include <fstream>
#include <algorithm>

// Реализация метода для сортировки по калориям (по убыванию)
void Candy::bubbleSortByCalories(std::vector<Candy>& candies) {
    int n = candies.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (candies[j].calories < candies[j + 1].calories) {
                std::swap(candies[j], candies[j + 1]);
            }
        }
    }
}

// Реализация метода для сортировки по названию (по возрастанию)
void Candy::bubbleSortByName(std::vector<Candy>& candies) {
    int n = candies.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (candies[j].name > candies[j + 1].name) {
                std::swap(candies[j], candies[j + 1]);
            }
        }
    }
}

// Реализация метода для вывода информации о конфете
void Candy::print() const {
    std::cout << name << " " << weight << " " << calories << " " << flavor << "\n";
}

// Реализация функции для чтения данных из файла
std::vector<Candy> readCandiesFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<Candy> candies;
    Candy temp;

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << "\n";
        std::cerr << "Please make sure the file exists and is in the correct directory.\n";
        return candies;
    }

    while (file >> temp.name >> temp.weight >> temp.calories >> temp.flavor) {
        candies.push_back(temp);
    }

    return candies;
}