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

    void addWeapon(Aweapon &src);

    void changeWeapon();

    void attack(AAlien &target);

    const char *getWeapon() const;

    int hp;
    int X;

    const char *getLives();

    const char *getScore();

    int Y;
    int score;
    int lives;
    Aweapon *weapon;
    int nbWeapon;
    int currentWeaponIndex;
};

#endif