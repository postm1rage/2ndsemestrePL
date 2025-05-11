#include "matrix.h"
#include <type_traits>
#include <stdexcept>

// Конструкторы
template <typename T>
Matrix<T>::Matrix(size_t rows, size_t cols) : rows(rows), cols(cols), data(rows, std::vector<T>(cols)) {}

template <typename T>
Matrix<T>::Matrix(size_t rows, size_t cols, const T& initValue) : 
    rows(rows), cols(cols), data(rows, std::vector<T>(cols, initValue)) {}

// Получение размеров матрицы
template <typename T>
size_t Matrix<T>::getRows() const { return rows; }

template <typename T>
size_t Matrix<T>::getCols() const { return cols; }

// Доступ к элементам
template <typename T>
T& Matrix<T>::operator()(size_t i, size_t j) {
    if (i >= rows || j >= cols) {
        throw std::out_of_range("Matrix indices out of range");
    }
    return data[i][j];
}

template <typename T>
const T& Matrix<T>::operator()(size_t i, size_t j) const {
    if (i >= rows || j >= cols) {
        throw std::out_of_range("Matrix indices out of range");
    }
    return data[i][j];
}

// Методы Set и Get
template <typename T>
void Matrix<T>::Set(size_t i, size_t j, const T& value) {
    if (i >= rows || j >= cols) {
        throw std::out_of_range("Matrix indices out of range");
    }
    data[i][j] = value;
}

template <typename T>
T Matrix<T>::Get(size_t i, size_t j) const {
    if (i >= rows || j >= cols) {
        throw std::out_of_range("Matrix indices out of range");
    }
    return data[i][j];
}

// Оператор сложения матриц
template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrix dimensions must agree for addition");
    }
    
    Matrix<T> result(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

// Оператор умножения матриц (специализация для строк)
template <>
Matrix<std::string> Matrix<std::string>::operator*(const Matrix<std::string>& other) const {
    throw std::invalid_argument("Matrix multiplication is not supported for strings");
}

// Оператор умножения матриц (общий случай)
template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("Matrix dimensions must agree for multiplication");
    }
    
    Matrix<T> result(rows, other.cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < other.cols; ++j) {
            T sum = T();
            for (size_t k = 0; k < cols; ++k) {
                sum += data[i][k] * other.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }
    return result;
}

// Операторы ввода/вывода
template <typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix) {
    for (size_t i = 0; i < matrix.rows; ++i) {
        for (size_t j = 0; j < matrix.cols; ++j) {
            os << matrix.data[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}

template <typename T>
std::istream& operator>>(std::istream& is, Matrix<T>& matrix) {
    for (size_t i = 0; i < matrix.rows; ++i) {
        for (size_t j = 0; j < matrix.cols; ++j) {
            is >> matrix.data[i][j];
        }
    }
    return is;
}

// Явная инстанциация шаблонов
template class Matrix<int>;
template class Matrix<double>;
template class Matrix<float>;
template class Matrix<std::string>;