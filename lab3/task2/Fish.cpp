#include "Fish.h"
#include <iostream>

void Fish::breathe() const {
    std::cout << "Fish is breathing underwater" << std::endl;
}

void Fish::eat() const {
    std::cout << "Fish is eating plankton" << std::endl;
}

void Fish::swim() const {
    std::cout << "Fish is swimming" << std::endl;
}