#include <iostream>
#include "Complex.h"

int main() {
    std::cout << "Enter real and imaginary parts for first complex number: ";
    double re1, im1;
    std::cin >> re1 >> im1;
    Complex z1(re1, im1);

    std::cout << "Enter real and imaginary parts for second complex number: ";
    double re2, im2;
    std::cin >> re2 >> im2;
    Complex z2(re2, im2);

    // Display numbers
    std::cout << "First number: ";
    z1.Print();
    std::cout << "Second number: ";
    z2.Print();

    // Arithmetic operations
    Complex sum = z1 + z2;
    std::cout << "Sum: ";
    sum.Print();

    Complex diff = z1 - z2;
    std::cout << "Difference: ";
    diff.Print();

    Complex prod = z1 * z2;
    std::cout << "Product: ";
    prod.Print();

    Complex quot = z1 / z2;
    std::cout << "Quotient: ";
    quot.Print();

    // Increment/Decrement
    Complex incr1 = ++z1;
    std::cout << "Prefix increment: ";
    incr1.Print();

    Complex incr2 = z1++;
    std::cout << "Postfix increment: ";
    incr2.Print();

    // Comparison
    std::cout << "z1 == z2: " << (z1 == z2) << std::endl;
    std::cout << "z1 >= z2: " << (z1 >= z2) << std::endl;

    // Scalar addition
    std::cout << "z1 + 2 = ";
    Complex z3 = 2 + z1;
    z3.Print();

    return 0;
}