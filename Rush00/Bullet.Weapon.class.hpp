#ifndef BULLET_WEAPON_CLASS_H
#define BULLET_WEAPON_CLASS_H

#include <iostream>

class Bullet {
public :
    Bullet();

    Bullet(int x, int y, int direction);

    ~Bullet();

    Bullet &operator=(const Bullet &rhs);

    int X;
    int Y;
    int direction;

};

#endif