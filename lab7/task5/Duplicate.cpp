#include "Duplicate.h"
#include <vector>
#include <string>

template <typename T>
void Duplicate(std::vector<T>& v) {
    v.insert(v.end(), v.begin(), v.end());
}

// Явные инстанциации для нужных типов
template void Duplicate<int>(std::vector<int>&);
template void Duplicate<std::string>(std::vector<std::string>&);