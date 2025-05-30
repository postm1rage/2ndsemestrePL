#include "Unique.h"
#include <vector>
#include <string>

template <typename Iter>
Iter Unique(Iter first, Iter last) {
    if (first == last) return last;
    Iter result = first;
    while (++first != last) {
        if (!(*result == *first)) {
            *(++result) = *first;
        }
    }
    return ++result;
}

// Явные инстанциации для нужных типов
template std::vector<int>::iterator Unique(std::vector<int>::iterator, std::vector<int>::iterator);
template std::vector<std::string>::iterator Unique(std::vector<std::string>::iterator, std::vector<std::string>::iterator);