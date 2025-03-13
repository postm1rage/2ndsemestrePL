#ifndef ODDEVENSEPARATOR_H
#define ODDEVENSEPARATOR_H

#include <vector>

class OddEvenSeparator {
private:
    std::vector<int> numbers; 
    std::vector<int> evens; 
    std::vector<int> odds;  

public:
    void add_number(int number); // Метод для добавления числа
    void even();                // Метод для вывода чётных чисел
    void odd();                 // Метод для вывода нечётных чисел
};

#endif // ODDEVENSEPARATOR_H