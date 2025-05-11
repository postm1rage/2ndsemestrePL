#include "array_utils.h"
#include <string>

template <typename T>
bool contains(const T& element, const T* array, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (array[i] == element) {
            return true;
        }
    }
    return false;
}

// Явные инстанциации шаблона для нужных типов
template bool contains<int>(const int&, const int*, size_t);
template bool contains<double>(const double&, const double*, size_t);
template bool contains<std::string>(const std::string&, const std::string*, size_t);