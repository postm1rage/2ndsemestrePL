#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <stdexcept>
#include <iostream>

template <typename T>
class Matrix {
private:
    size_t rows;
    size_t cols;
    std::vector<std::vector<T>> data;

public:
    // Конструкторы
    Matrix(size_t rows, size_t cols);
    Matrix(size_t rows, size_t cols, const T& initValue);
    
    // Деструктор
    ~Matrix() = default;
    
    // Получение размеров матрицы
    size_t getRows() const;
    size_t getCols() const;
    
    // Доступ к элементам
    T& operator()(size_t i, size_t j);
    const T& operator()(size_t i, size_t j) const;
    
    // Методы Set и Get
    void Set(size_t i, size_t j, const T& value);
    T Get(size_t i, size_t j) const;
    
    // Операторы
    Matrix operator+(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    
    // Операторы ввода/вывода
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Matrix<U>& matrix);
    
    template <typename U>
    friend std::istream& operator>>(std::istream& is, Matrix<U>& matrix);
};

#include "matrix.cpp"

#endif // MATRIX_H