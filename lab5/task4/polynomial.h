#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "complex.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

template <typename T>
class Polynomial {
private:
    std::vector<T> coefficients; // Коэффициенты по возрастанию степеней

public:
    // Конструкторы
    Polynomial() : coefficients(1, T()) {} // Многочлен нулевой степени (значение по умолчанию)
    Polynomial(const T& scalar) : coefficients(1, scalar) {} // Многочлен нулевой степени с заданным значением
    Polynomial(const std::vector<T>& coeffs) : coefficients(coeffs) {} // По вектору коэффициентов

    // Операторы сравнения
    bool operator==(const Polynomial& other) const {
        return coefficients == other.coefficients;
    }

    bool operator!=(const Polynomial& other) const {
        return !(*this == other);
    }

    template <typename U>
    bool operator==(const U& scalar) const {
        if (Degree() != 0) return false;
        return coefficients[0] == T(scalar);
    }

    template <typename U>
    bool operator!=(const U& scalar) const {
        return !(*this == scalar);
    }

    // Арифметические операторы
    Polynomial operator+(const Polynomial& other) const {
        std::vector<T> result(std::max(coefficients.size(), other.coefficients.size()), T());
        for (size_t i = 0; i < result.size(); ++i) {
            if (i < coefficients.size()) result[i] += coefficients[i];
            if (i < other.coefficients.size()) result[i] += other.coefficients[i];
        }
        return Polynomial(result);
    }

    Polynomial operator-(const Polynomial& other) const {
        std::vector<T> result(std::max(coefficients.size(), other.coefficients.size()), T());
        for (size_t i = 0; i < result.size(); ++i) {
            if (i < coefficients.size()) result[i] += coefficients[i];
            if (i < other.coefficients.size()) result[i] -= other.coefficients[i];
        }
        return Polynomial(result);
    }

    Polynomial operator*(const Polynomial& other) const {
        std::vector<T> result(coefficients.size() + other.coefficients.size() - 1, T());
        for (size_t i = 0; i < coefficients.size(); ++i) {
            for (size_t j = 0; j < other.coefficients.size(); ++j) {
                result[i + j] += coefficients[i] * other.coefficients[j];
            }
        }
        return Polynomial(result);
    }

    Polynomial& operator+=(const Polynomial& other) {
        *this = *this + other;
        return *this;
    }

    Polynomial& operator-=(const Polynomial& other) {
        *this = *this - other;
        return *this;
    }

    Polynomial& operator*=(const Polynomial& other) {
        *this = *this * other;
        return *this;
    }

    template <typename U>
    Polynomial operator+(const U& scalar) const {
        Polynomial result(*this);
        if (result.coefficients.empty()) {
            result.coefficients.push_back(T(scalar));
        } else {
            result.coefficients[0] += T(scalar);
        }
        return result;
    }

    template <typename U>
    Polynomial operator-(const U& scalar) const {
        Polynomial result(*this);
        if (result.coefficients.empty()) {
            result.coefficients.push_back(-T(scalar));
        } else {
            result.coefficients[0] -= T(scalar);
        }
        return result;
    }

    template <typename U>
    Polynomial operator*(const U& scalar) const {
        Polynomial result(*this);
        for (auto& coeff : result.coefficients) {
            coeff *= T(scalar);
        }
        return result;
    }

    template <typename U>
    Polynomial& operator+=(const U& scalar) {
        if (coefficients.empty()) {
            coefficients.push_back(T(scalar));
        } else {
            coefficients[0] += T(scalar);
        }
        return *this;
    }

    template <typename U>
    Polynomial& operator-=(const U& scalar) {
        if (coefficients.empty()) {
            coefficients.push_back(-T(scalar));
        } else {
            coefficients[0] -= T(scalar);
        }
        return *this;
    }

    template <typename U>
    Polynomial& operator*=(const U& scalar) {
        for (auto& coeff : coefficients) {
            coeff *= T(scalar);
        }
        return *this;
    }

    // Оператор доступа к коэффициенту
    const T& operator[](size_t degree) const {
        static const T zero = T();
        if (degree >= coefficients.size()) return zero;
        return coefficients[degree];
    }

    // Метод для вычисления степени многочлена
    int Degree() const {
        if (coefficients.empty()) return -1; // Нулевой многочлен
        for (int i = coefficients.size() - 1; i >= 0; --i) {
            if (coefficients[i] != T()) return i;
        }
        return -1; // Все коэффициенты нулевые
    }

    // Оператор вычисления значения многочлена в точке
    T operator()(const T& x) const {
        T result = T();
        if (coefficients.empty()) return result;
        
        // Используем схему Горнера для эффективного вычисления
        for (int i = Degree(); i >= 0; --i) {
            result = result * x + coefficients[i];
        }
        return result;
    }

    // Дружественная функция для вывода в поток
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& poly) {
        int degree = poly.Degree();
        if (degree == -1) {
            os << "0";
            return os;
        }
        
        for (int i = degree; i >= 0; --i) {
            os << poly.coefficients[i];
            if (i != 0) os << " ";
        }
        return os;
    }
};

// Внешние операторы для скалярных операций
template <typename T, typename U>
Polynomial<T> operator+(const U& scalar, const Polynomial<T>& poly) {
    return poly + scalar;
}

template <typename T, typename U>
Polynomial<T> operator-(const U& scalar, const Polynomial<T>& poly) {
    return Polynomial<T>(scalar) - poly;
}

template <typename T, typename U>
Polynomial<T> operator*(const U& scalar, const Polynomial<T>& poly) {
    return poly * scalar;
}

#endif // POLYNOMIAL_H