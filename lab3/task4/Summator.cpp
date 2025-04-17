#include "Summator.h"

int Summator::transform(int i) const {
    return i; // Тождественное преобразование
}

int Summator::sum(int N) const {
    int total = 0;
    for (int i = 1; i <= N; ++i) {
        total += transform(i);
    }
    return total;
}