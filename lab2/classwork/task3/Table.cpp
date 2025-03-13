#include "Table.h"
#include <iostream>

Table::Table(int rows, int cols) : rows(rows), cols(cols) {
    data = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new int[cols](); // Инициализируем нулями
    }
}

Table::~Table() {
    // Освобождаем память
    for (int i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

// Получить значение из ячейки
int Table::get_value(int row, int col) {
    return data[row][col];
}

// Установить значение в ячейку
void Table::set_value(int row, int col, int value) {
    data[row][col] = value;
}

// Получить количество строк
int Table::n_rows() {
    return rows;
}

// Получить количество столбцов
int Table::n_cols() {
    return cols;
}

// Вывести таблицу на экран
void Table::print() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Вычислить среднее арифметическое
double Table::average() {
    double sum = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum += data[i][j];
        }
    }
    return sum / (rows * cols);
}