#include "Rational.h"
#include <iostream>
#include <cassert>

int main() {
    // Тестирование конструктора
    Rational r1(6, 8);
    assert(r1.Numerator() == 3 && r1.Denominator() == 4);
    
    Rational r2(-2, -4);
    assert(r2.Numerator() == 1 && r2.Denominator() == 2);
    
    Rational r3(3, -9);
    assert(r3.Numerator() == -1 && r3.Denominator() == 3);
    
    // Тестирование арифметических операций
    Rational sum = r1 + r2;
    assert(sum.Numerator() == 5 && sum.Denominator() == 4);
    
    Rational diff = r1 - r2;
    assert(diff.Numerator() == 1 && diff.Denominator() == 4);
    
    Rational prod = r1 * r2;
    assert(prod.Numerator() == 3 && prod.Denominator() == 8);
    
    Rational quot = r1 / r2;
    assert(quot.Numerator() == 3 && quot.Denominator() == 2);
    
    // Тестирование операторов с int
    Rational r4 = r1 + 1;
    assert(r4.Numerator() == 7 && r4.Denominator() == 4);
    
    Rational r5 = 2 - r2;
    assert(r5.Numerator() == 3 && r5.Denominator() == 2);
    
    // Тестирование операторов присваивания
    r1 += r2;
    assert(r1.Numerator() == 5 && r1.Denominator() == 4);
    
    r1 *= r3;
    assert(r1.Numerator() == -5 && r1.Denominator() == 12);
    
    // Тестирование ввода/вывода
    Rational r6;
    std::cout << "Enter fraction (format a/b): ";
    std::cin >> r6;
    std::cout << "You entered: " << r6 << std::endl;
    
    std::cout << "All tests passed!" << std::endl;
    return 0;
}