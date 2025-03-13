#include "Stock.h"
#include <iostream>

int main() {
    Stock stock;

    // Добавляем коробки
    stock.Add(10, 5); // id = 0
    stock.Add(15, 3); // id = 1
    stock.Add(20, 8); // id = 2
    stock.Add(10, 7); // id = 3

    // Тестируем GetByW
    std::cout << "GetByW(12): " << stock.GetByW(12) << std::endl; // Должен вернуть id = 1 (грузоподъемность 15)
    std::cout << "GetByW(10): " << stock.GetByW(10) << std::endl; // Должен вернуть id = 0 (грузоподъемность 10, добавлена раньше)

    // Тестируем GetByV
    std::cout << "GetByV(6): " << stock.GetByV(6) << std::endl; // Должен вернуть id = 3 (объем 7)
    std::cout << "GetByV(8): " << stock.GetByV(8) << std::endl; // Должен вернуть id = 2 (объем 8)

    // Проверяем, что коробки удаляются
    std::cout << "GetByW(10): " << stock.GetByW(10) << std::endl; // Должен вернуть -1 (подходящих коробок нет)

    return 0;
}