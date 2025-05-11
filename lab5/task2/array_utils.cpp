#include "array_utils.h"
#include <iostream>

template <typename T>
bool contains(const T& element, const T* array, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (array[i] == element) {
            return true;
        }
    }
    return false;
}

template <typename T>
bool change(const T& a, const T& b, T* array, size_t size) {
    if (!contains(a, array, size) || !contains(b, array, size)) {
        std::cerr << "Error: One or both elements are not present in the array!\n";
        return false;
    }

    size_t indexA = 0, indexB = 0;
    for (size_t i = 0; i < size; ++i) {
        if (array[i] == a) indexA = i;
        if (array[i] == b) indexB = i;
    }

    std::swap(array[indexA], array[indexB]);
    std::cout << "Elements \"" << a << "\" and \"" << b << "\" were successfully swapped.\n";
    return true;
}

template <typename T>
void printArray(const T* array, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

template bool contains<int>(const int&, const int*, size_t);
template bool contains<double>(const double&, const double*, size_t);
template bool contains<std::string>(const std::string&, const std::string*, size_t);

template bool change<int>(const int&, const int&, int*, size_t);
template bool change<double>(const double&, const double&, double*, size_t);
template bool change<std::string>(const std::string&, const std::string&, std::string*, size_t);

template void printArray<int>(const int*, size_t);
template void printArray<double>(const double*, size_t);
template void printArray<std::string>(const std::string*, size_t);