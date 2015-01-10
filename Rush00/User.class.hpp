#ifndef USER_CLASS_H
#define USER_CLASS_H

#include "AAlien.class.hpp"
#include "Aweapon.class.hpp"
#include <sstream>
#include <iostream>


class User {
public:
    User();

    ~User();

    void takeDamage(int amount);

    void attack(AAlien &target);

    Aweapon *getWeapon() const;

    int hp;
    int X;

    const char *getLives();

    const char *getScore();
    int Y;
    int score;
    int lives;
    Aweapon *weapon;
};

#endif