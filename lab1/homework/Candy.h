#ifndef CANDY_H
#define CANDY_H

#include <string>
#include <vector>

// Структура Candy
struct Candy {
    std::string name;       // Название конфеты
    double weight;          // Вес конфеты в граммах
    int calories;           // Количество калорий
    std::string flavor;     // Вкус конфеты

    // Методы для сортировки
    static void bubbleSortByCalories(std::vector<Candy>& candies);
    static void bubbleSortByName(std::vector<Candy>& candies);

    // Метод для вывода информации о конфете
    void print() const;
};

// Функция для чтения данных из файла
std::vector<Candy> readCandiesFromFile(const std::string& filename);

#endif