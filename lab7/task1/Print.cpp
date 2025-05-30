#include "Print.h"
#include <iostream>
#include <vector>
#include <list>
#include <string>

template <typename Container>
void Print(const Container& container, const std::string& delimiter) {
    bool first = true;
    for (const auto& item : container) {
        if (!first) {
            std::cout << delimiter;
        }
        std::cout << item;
        first = false;
    }
    std::cout << "\n";
}

// Явные инстанциации
template void Print(const std::vector<int>&, const std::string&);
template void Print(const std::vector<double>&, const std::string&);
template void Print(const std::list<std::string>&, const std::string&);