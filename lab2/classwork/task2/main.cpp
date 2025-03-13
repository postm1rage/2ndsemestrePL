#include "OddEvenSeparator.h"

int main() {
    OddEvenSeparator separator;

    separator.add_number(1);
    separator.add_number(2);
    separator.add_number(3);
    separator.add_number(4);
    separator.add_number(5);

    separator.even(); // 2 4
    separator.odd(); // 1 3 5

    return 0;
}