#ifndef ANIMAL_H
#define ANIMAL_H

class Animal {
public:
    virtual ~Animal() {} // Виртуальный деструктор
    
    // Чисто виртуальные методы (интерфейс)
    virtual void breathe() const = 0;
    virtual void eat() const = 0;
};

#endif // ANIMAL_H