#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <cstddef> // Для size_t

// Шаблонная функция для проверки наличия элемента в массиве
template <typename T>
bool contains(const T& element, const T* array, size_t size);

#endif // ARRAY_UTILS_H