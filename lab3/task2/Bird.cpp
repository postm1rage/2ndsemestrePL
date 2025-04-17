#include "Bird.h"
#include <iostream>

void Bird::breathe() const {
    std::cout << "Bird is breathing air" << std::endl;
}

void Bird::eat() const {
    std::cout << "Bird is eating seeds" << std::endl;
}

void Bird::lay_eggs() const {
    std::cout << "Bird is laying eggs" << std::endl;
}