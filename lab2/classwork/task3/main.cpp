#include "Table.h"
#include <iostream>
int main() {
    // Создаем таблицу 3x4
    Table table(3, 4);

    // Заполняем таблицу значениями
    table.set_value(0, 0, 1);
    table.set_value(0, 1, 2);
    table.set_value(0, 2, 3);
    table.set_value(0, 3, 4);
    table.set_value(1, 0, 5);
    table.set_value(1, 1, 6);
    table.set_value(1, 2, 7);
    table.set_value(1, 3, 8);
    table.set_value(2, 0, 9);
    table.set_value(2, 1, 10);
    table.set_value(2, 2, 11);
    table.set_value(2, 3, 12);

    // Выводим таблицу
    std::cout << "Table:" << std::endl;
    table.print();

    // Получаем количество строк и столбцов
    std::cout << "Rows: " << table.n_rows() << std::endl;
    std::cout << "Columns: " << table.n_cols() << std::endl;

    // Получаем значение из ячейки
    std::cout << "Value at (1, 2): " << table.get_value(1, 2) << std::endl;

    // Вычисляем среднее арифметическое
    std::cout << "Average: " << table.average() << std::endl;

    return 0;
}