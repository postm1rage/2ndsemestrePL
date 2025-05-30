#include "DuplicateChecker.h"

void CheckDuplicates() {
    std::unordered_set<int> seen;
    int num;
    while (std::cin >> num) {
        if (seen.count(num)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
            seen.insert(num);
        }
    }
}