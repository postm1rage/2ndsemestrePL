#ifndef STOCK_H
#define STOCK_H

#include <vector>
#include <algorithm>

class Stock {
private:
    struct Box {
        int id;       // Серийный номер
        int weight;   // Грузоподъемность
        int volume;   // Объем
        int time;     // Время добавления (чем меньше, тем раньше добавлена)
    };

    std::vector<Box> boxes; // Вектор для хранения коробок
    int timeCounter;        // Счетчик времени для определения порядка добавления

public:
    Stock(); // Конструктор

    // Методы
    void Add(int w, int v); // Добавить коробку
    int GetByW(int min_w);  // Получить коробку по грузоподъемности
    int GetByV(int min_v);  // Получить коробку по объему
};

#endif // STOCK_H