#include "Bell.h"
#include <iostream>

Bell::Bell() : isDing(true) {}

void Bell::sound() {
    if (isDing) {
        std::cout << "ding" << std::endl;
    } else {
        std::cout << "dong" << std::endl;
    }
    isDing = !isDing; 
}