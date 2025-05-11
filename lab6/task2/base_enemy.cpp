#include "base_enemy.h"

BaseEnemy::BaseEnemy(int pos_x, int pos_y, const Weapon& weapon, int hp)
    : BaseCharacter(pos_x, pos_y, hp), weapon(weapon) {}

void BaseEnemy::hit(BaseCharacter& target) {
    weapon.hit(*this, target);
}

std::ostream& operator<<(std::ostream& os, const BaseEnemy& enemy) {
    os << "The enemy on position (" << enemy.pos_x << ", " << enemy.pos_y 
       << ") with weapon " << enemy.weapon;
    return os;
}