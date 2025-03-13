#include "Complex.h"
#include <cmath>
#include <iostream>

// Конструктор по умолчанию
Complex::Complex() : re(0), im(0) {}

// Конструктор с параметрами
Complex::Complex(double x, double y) : re(x), im(y) {}

// Получить действительную часть
double Complex::GetRe() const {
    return re;
}

// Получить мнимую часть
double Complex::GetIm() const {
    return im;
}

// Установить действительную часть
void Complex::SetRe(double x) {
    re = x;
}

// Установить мнимую часть
void Complex::SetIm(double y) {
    im = y;
}

// Модуль комплексного числа
double Complex::Abs() const {
    return std::sqrt(re * re + im * im);
}

// Аргумент комплексного числа
double Complex::Arg() const {
    return std::atan2(im, re);
}

// Вывод в стандартной форме
void Complex::Print() const {
    std::cout << re << " + i*" << im << std::endl;
}

// Вывод в тригонометрической форме
void Complex::TrigPrint() const {
    double rho = Abs();
    double phi = Arg();
    std::cout << rho << "*(cos(" << phi << ") + i*sin(" << phi << "))" << std::endl;
}

// Вывод в показательной форме
void Complex::ExpPrint() const {
    double rho = Abs();
    double phi = Arg();
    std::cout << rho << "*e^(i*" << phi << ")" << std::endl;
}

// Сложение
Complex Complex::Add(const Complex& z) const {
    return Complex(re + z.re, im + z.im);
}

// Вычитание
Complex Complex::Sub(const Complex& z) const {
    return Complex(re - z.re, im - z.im);
}

// Умножение
Complex Complex::Mult(const Complex& z) const {
    return Complex(re * z.re - im * z.im, re * z.im + im * z.re);
}

// Деление
Complex Complex::Div(const Complex& z) const {
    double denominator = z.re * z.re + z.im * z.im;
    return Complex((re * z.re + im * z.im) / denominator, (im * z.re - re * z.im) / denominator);
}