#include "base_character.h"

BaseCharacter::BaseCharacter(int pos_x, int pos_y, int hp) 
    : pos_x(pos_x), pos_y(pos_y), hp(hp) {}

void BaseCharacter::move(int delta_x, int delta_y) {
    pos_x += delta_x;
    pos_y += delta_y;
}

bool BaseCharacter::is_alive() const {
    return hp > 0;
}

void BaseCharacter::get_damage(int amount) {
    hp -= amount;
    if (hp < 0) hp = 0;
}

int BaseCharacter::get_x() const { return pos_x; }
int BaseCharacter::get_y() const { return pos_y; }
int BaseCharacter::get_hp() const { return hp; }