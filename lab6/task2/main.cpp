#include <iostream>
#include "main_hero.h"
#include "base_enemy.h"
#include "weapon.h"
#include "exceptions.h"

int main() {
    try {
        // Создаем оружие
        Weapon sword("Sword", 30, 5);
        Weapon bow("Bow", 20, 15);
        Weapon axe("Axe", 40, 3);
        
        // Создаем героя
        MainHero hero(0, 0, "Edik", 100);
        
        // Создаем врагов
        BaseEnemy enemy1(3, 4, sword, 50);
        BaseEnemy enemy2(10, 10, bow, 60);
        BaseEnemy enemy3(2, 1, axe, 70);
        
        // Битва
        std::cout << "The battle starts!" << std::endl;
        
        // Герой без оружия
        hero.hit(enemy1);
        
        // Подбираем оружие
        hero.add_weapon(sword);
        hero.add_weapon(bow);
        
        // Атакуем врагов
        hero.hit(enemy1);
        hero.hit(enemy2); // Должен быть слишком далеко для меча
        
        // Меняем оружие
        hero.next_weapon();
        hero.hit(enemy2); // Теперь можно достать луком
        
        // Лечение
        hero.heal(30);
        
        // Еще оружие
        hero.add_weapon(axe);
        hero.next_weapon();
        hero.hit(enemy3);
        
        // Проверяем состояние врагов
        std::cout << enemy1 << std::endl;
        std::cout << enemy2 << std::endl;
        std::cout << enemy3 << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}