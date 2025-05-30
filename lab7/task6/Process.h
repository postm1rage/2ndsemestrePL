#pragma once
#include <vector>
#include <algorithm>
#include <iterator>

// Объявление PrintResults
template <typename Iter>
void PrintResults(Iter first, Iter last);

// Реализация Process
template <typename T>
void Process(const std::vector<T>& data) {
    std::vector<T> filtered;
    std::copy_if(
        data.begin(),
        data.end(),
        std::back_inserter(filtered),
        [](const T& x) { return x > 0; }
    );
    PrintResults(filtered.begin(), filtered.end());
}