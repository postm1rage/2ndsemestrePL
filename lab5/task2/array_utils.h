#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <iostream>
#include <string>
#include <utility> // Для std::swap

template <typename T>
bool contains(const T& element, const T* array, size_t size);

template <typename T>
bool change(const T& a, const T& b, T* array, size_t size);

template <typename T>
void printArray(const T* array, size_t size);

#endif // ARRAY_UTILS_H