#ifndef AWEAPON_CLASS_H
#define AWEAPON_CLASS_H
#include <iostream>

class Aweapon{
public:
    Aweapon();
    Aweapon(std::string name, int damage);
    ~Aweapon();
    int getDamage();
protected:
    int damage;
    std::string name;
};

#endif