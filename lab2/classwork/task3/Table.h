#ifndef TABLE_H
#define TABLE_H

class Table {
private:
    int rows;
    int cols;
    int** data;

public:
    Table(int rows, int cols);

    ~Table();

    int get_value(int row, int col);       // Получить значение из ячейки
    void set_value(int row, int col, int value); // Установить значение в ячейку
    int n_rows();                          // Получить количество строк
    int n_cols();                          // Получить количество столбцов
    void print();                          // Вывести таблицу на экран
    double average();                      // Вычислить среднее арифметическое
};

#endif // TABLE_H