#ifndef BASE_ENEMY_H
#define BASE_ENEMY_H

#include "base_character.h"
#include "weapon.h"
#include <iostream>

class BaseEnemy : public BaseCharacter {
private:
    Weapon weapon;

public:
    BaseEnemy(int pos_x, int pos_y, const Weapon& weapon, int hp);
    
    void hit(BaseCharacter& target);
    
    friend std::ostream& operator<<(std::ostream& os, const BaseEnemy& enemy);
};

#endif // BASE_ENEMY_H