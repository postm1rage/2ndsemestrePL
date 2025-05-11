#include "matrix.h"
#include <iostream>

int main() {
    // Демонстрация работы с числовым типом (int)
    std::cout << "Integer Matrix Demonstration:\n";
    Matrix<int> intMat1(2, 2);
    intMat1.Set(0, 0, 1); intMat1.Set(0, 1, 2);
    intMat1.Set(1, 0, 3); intMat1.Set(1, 1, 4);
    
    Matrix<int> intMat2(2, 2);
    intMat2.Set(0, 0, 5); intMat2.Set(0, 1, 6);
    intMat2.Set(1, 0, 7); intMat2.Set(1, 1, 8);
    
    std::cout << "Matrix 1:\n" << intMat1;
    std::cout << "Matrix 2:\n" << intMat2;
    
    Matrix<int> intSum = intMat1 + intMat2;
    std::cout << "Sum:\n" << intSum;
    
    Matrix<int> intProd = intMat1 * intMat2;
    std::cout << "Product:\n" << intProd;
    
    // Демонстрация работы со строковым типом
    std::cout << "\nString Matrix Demonstration:\n";
    Matrix<std::string> strMat1(2, 2);
    strMat1.Set(0, 0, "Hello"); strMat1.Set(0, 1, "World");
    strMat1.Set(1, 0, "C++");   strMat1.Set(1, 1, "Matrix");
    
    Matrix<std::string> strMat2(2, 2);
    strMat2.Set(0, 0, "Good");  strMat2.Set(0, 1, "Morning");
    strMat2.Set(1, 0, "STL");   strMat2.Set(1, 1, "Vector");
    
    std::cout << "Matrix 1:\n" << strMat1;
    std::cout << "Matrix 2:\n" << strMat2;
    
    Matrix<std::string> strSum = strMat1 + strMat2;
    std::cout << "Concatenation (sum):\n" << strSum;
    
    try {
        Matrix<std::string> strProd = strMat1 * strMat2;
    } catch (const std::invalid_argument& e) {
        std::cout << "Multiplication not supported for string matrices: " << e.what() << "\n";
    }
    
    return 0;
}