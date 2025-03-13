#include "Complex.h"

int main() {
    // Создаем комплексные числа
    Complex z1(3, 4); // 3 + 4i
    Complex z2(1, -1); // 1 - i

    // Выводим числа
    std::cout << "z1: ";
    z1.Print();
    std::cout << "z2: ";
    z2.Print();

    // Выводим модуль и аргумент
    std::cout << "|z1| = " << z1.Abs() << std::endl;
    std::cout << "arg(z1) = " << z1.Arg() << std::endl;

    // Выводим в тригонометрической и показательной формах
    std::cout << "z1 in trigonometric form: ";
    z1.TrigPrint();
    std::cout << "z1 in exponential form: ";
    z1.ExpPrint();

    // Операции
    Complex sum = z1.Add(z2);
    Complex diff = z1.Sub(z2);
    Complex prod = z1.Mult(z2);
    Complex quot = z1.Div(z2);

    std::cout << "z1 + z2: ";
    sum.Print();
    std::cout << "z1 - z2: ";
    diff.Print();
    std::cout << "z1 * z2: ";
    prod.Print();
    std::cout << "z1 / z2: ";
    quot.Print();

    return 0;
}