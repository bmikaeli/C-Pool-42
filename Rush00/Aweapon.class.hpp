#ifndef AWEAPON_CLASS_H
#define AWEAPON_CLASS_H

#include <iostream>
#include <sstream>


class Aweapon {
public:
    Aweapon();

    Aweapon(Aweapon &src);

    Aweapon(std::string name, int damage, char *skin);

    ~Aweapon();

    int getDamage();

    const char *getName();

    Aweapon &operator=(Aweapon &rhs);

    char *skin;

protected:
    int damage;
    std::string name;
};

#endif