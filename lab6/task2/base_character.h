#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H

class Weapon;

class BaseCharacter {
protected:
    int pos_x;
    int pos_y;
    int hp;

public:
    BaseCharacter(int pos_x, int pos_y, int hp);
    
    virtual void move(int delta_x, int delta_y);
    bool is_alive() const;
    void get_damage(int amount);
    int get_x() const;
    int get_y() const;
    int get_hp() const;
};

#endif // BASE_CHARACTER_H