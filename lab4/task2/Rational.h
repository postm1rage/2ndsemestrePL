#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <numeric> // Для std::gcd
#include <stdexcept> // Для std::invalid_argument

class Rational {
private:
    int numerator;
    int denominator;

    void Normalize(); // Приведение к несократимому виду

public:
    // Конструкторы
    Rational(int num = 0, int denom = 1);
    
    // Получение числителя и знаменателя
    int Numerator() const;
    int Denominator() const;

    // Арифметические операторы
    Rational operator+(const Rational& rhs) const;
    Rational operator-(const Rational& rhs) const;
    Rational operator*(const Rational& rhs) const;
    Rational operator/(const Rational& rhs) const;
    
    // Унарные операторы
    Rational operator+() const;
    Rational operator-() const;
    
    // Операторы присваивания
    Rational& operator+=(const Rational& rhs);
    Rational& operator-=(const Rational& rhs);
    Rational& operator*=(const Rational& rhs);
    Rational& operator/=(const Rational& rhs);
    
    // Операторы сравнения
    bool operator==(const Rational& rhs) const;
    bool operator!=(const Rational& rhs) const;
    
    // Дружественные операторы для работы с int
    friend Rational operator+(const Rational& r, int value);
    friend Rational operator+(int value, const Rational& r);
    friend Rational operator-(const Rational& r, int value);
    friend Rational operator-(int value, const Rational& r);
    friend Rational operator*(const Rational& r, int value);
    friend Rational operator*(int value, const Rational& r);
    friend Rational operator/(const Rational& r, int value);
    friend Rational operator/(int value, const Rational& r);
    
    // Ввод/вывод
    friend std::ostream& operator<<(std::ostream& os, const Rational& r);
    friend std::istream& operator>>(std::istream& is, Rational& r);
};

#endif // RATIONAL_H