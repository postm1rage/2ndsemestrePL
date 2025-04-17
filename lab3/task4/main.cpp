#include <iostream>
#include "Summator.h"
#include "SquareSummator.h"
#include "CubeSummator.h"

void testSummator(Summator* s, int N, const std::string& name) {
    std::cout << name << " sum from 1 to " << N << " = " << s->sum(N) << std::endl;
}

int main() {
    const int N = 5;
    
    // Раннее связывание
    Summator base;
    SquareSummator square;
    CubeSummator cube;
    
    std::cout << "Early binding results:\n";
    std::cout << "Linear sum: " << base.sum(N) << std::endl;
    std::cout << "Square sum: " << square.sum(N) << std::endl;
    std::cout << "Cube sum: " << cube.sum(N) << std::endl;
    
    // Позднее связывание
    Summator* ptr1 = &base;
    Summator* ptr2 = &square;
    Summator* ptr3 = &cube;
    
    std::cout << "\nLate binding results:\n";
    testSummator(ptr1, N, "Linear");
    testSummator(ptr2, N, "Square");
    testSummator(ptr3, N, "Cube");
    
    // Проверка по формулам
    std::cout << "\nFormula verification:\n";
    std::cout << "Linear (formula): " << N*(N+1)/2 << std::endl;
    std::cout << "Square (formula): " << N*(N+1)*(2*N+1)/6 << std::endl;
    std::cout << "Cube (formula): " << (N*(N+1)/2)*(N*(N+1)/2) << std::endl;
    
    return 0;
}