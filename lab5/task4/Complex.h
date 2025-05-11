#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    // Операторы сравнения
    bool operator==(const Complex& other) const {
        return real == other.real && imaginary == other.imaginary;
    }

    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    // Арифметические операторы
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    Complex operator*(const Complex& other) const {
        return Complex(
            real * other.real - imaginary * other.imaginary,
            real * other.imaginary + imaginary * other.real
        );
    }

    Complex& operator+=(const Complex& other) {
        real += other.real;
        imaginary += other.imaginary;
        return *this;
    }

    Complex& operator-=(const Complex& other) {
        real -= other.real;
        imaginary -= other.imaginary;
        return *this;
    }

    Complex& operator*=(const Complex& other) {
        double new_real = real * other.real - imaginary * other.imaginary;
        double new_imaginary = real * other.imaginary + imaginary * other.real;
        real = new_real;
        imaginary = new_imaginary;
        return *this;
    }

    Complex& operator*=(double scalar) {
        real *= scalar;
        imaginary *= scalar;
        return *this;
    }

    // Дружественная функция для вывода
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << "(" << c.real << ", " << c.imaginary << ")";
        return os;
    }
};

#endif // COMPLEX_H