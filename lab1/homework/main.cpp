#include "Candy.h"
#include <iostream>

int main() {
    // Чтение данных из файла
    std::vector<Candy> candies = readCandiesFromFile("candies.txt");

    // Сортировка по калориям (по убыванию)
    Candy::bubbleSortByCalories(candies);
    std::cout << "Sorted by calories (descending):\n";
    for (const auto& candy : candies) {
        candy.print();
    }

    // Сортировка по названию (по возрастанию)
    Candy::bubbleSortByName(candies);
    std::cout << "\nSorted by name (ascending):\n";
    for (const auto& candy : candies) {
        candy.print();
    }

    return 0;
}