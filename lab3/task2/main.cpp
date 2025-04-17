/*
 * Автор: [Ваше имя]
 * Программа демонстрирует работу иерархии классов животных
 * с использованием раннего и позднего связывания
 */

#include <iostream>
#include "Animal.h"
#include "Fish.h"
#include "Bird.h"
#include "FlyingBird.h"

void testAnimal(const Animal& animal) {
    std::cout << "\nTesting animal:" << std::endl;
    animal.breathe();
    animal.eat();
}

int main() {
    std::cout << "=== Testing with early binding ===" << std::endl;
    
    // Раннее связывание (статический полиморфизм)
    Fish fish;
    Bird bird;
    FlyingBird flyingBird;
    
    std::cout << "\nTesting Fish:" << std::endl;
    fish.breathe();
    fish.eat();
    fish.swim();
    
    std::cout << "\nTesting Bird:" << std::endl;
    bird.breathe();
    bird.eat();
    bird.lay_eggs();
    
    std::cout << "\nTesting FlyingBird:" << std::endl;
    flyingBird.breathe();
    flyingBird.eat();
    flyingBird.lay_eggs();
    flyingBird.fly();
    
    return 0;
}