#ifndef MAIN_HERO_H
#define MAIN_HERO_H

#include "base_character.h"
#include "weapon.h"
#include <vector>
#include <string>

class BaseEnemy;

class MainHero : public BaseCharacter {
private:
    std::string name;
    std::vector<Weapon> weapons;
    int current_weapon_index;

public:
    MainHero(int pos_x, int pos_y, const std::string& name, int hp);
    
    void hit(BaseEnemy& target);
    void add_weapon(const Weapon& weapon);
    void next_weapon();
    void heal(int amount);
    
    const std::string& getName() const;
};

#endif // MAIN_HERO_H