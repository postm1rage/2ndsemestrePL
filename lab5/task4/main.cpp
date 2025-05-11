#include "polynomial.h"
#include "complex.h"
#include <iostream>

int main() {
    // Тестирование с int
    Polynomial<int> p1({1, 2, 3}); // 3x^2 + 2x + 1
    std::cout << "p1: " << p1 << std::endl;
    std::cout << "Degree of p1: " << p1.Degree() << std::endl;
    std::cout << "p1(2): " << p1(2) << std::endl;

    // Тестирование с Complex
    Complex c1(1, 1), c2(2, -1), c3(0, 1);
    Polynomial<Complex> p2({c1, c2, c3}); // (0+1i)x^2 + (2-1i)x + (1+1i)
    std::cout << "\np2: " << p2 << std::endl;
    std::cout << "Degree of p2: " << p2.Degree() << std::endl;
    
    Complex x(1, 0);
    std::cout << "p2(1+0i): " << p2(x) << std::endl;

    // Операции с комплексными числами
    Polynomial<Complex> p3 = p2 + Complex(1, 0);
    std::cout << "\np2 + 1: " << p3 << std::endl;

    Polynomial<Complex> p4 = p2 * Complex(0, 1);
    std::cout << "p2 * i: " << p4 << std::endl;

    return 0;
}