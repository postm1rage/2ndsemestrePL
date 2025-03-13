#ifndef COMPLEX_H
#define COMPLEX_H

#include <cmath>
#include <iostream>

class Complex {
private:
    double re;
    double im;

public:
    // Конструкторы
    Complex(); // По умолчанию
    Complex(double x, double y); // С параметрами

    double GetRe() const;
    double GetIm() const;
    void SetRe(double x);
    void SetIm(double y);

    // Методы
    double Abs() const; // Модуль комплексного числа
    double Arg() const; // Аргумент комплексного числа
    void Print() const; // Вывод в стандартной форме
    void TrigPrint() const; // Вывод в тригонометрической форме
    void ExpPrint() const; // Вывод в показательной форме

    Complex Add(const Complex& z) const;
    Complex Sub(const Complex& z) const;
    Complex Mult(const Complex& z) const;
    Complex Div(const Complex& z) const;
};

#endif // COMPLEX_H