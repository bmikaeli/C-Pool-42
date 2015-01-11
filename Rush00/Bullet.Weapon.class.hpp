#ifndef BULLET_WEAPON_CLASS_H
#define BULLET_WEAPON_CLASS_H

#include <iostream>

class Bullet {
public :
    Bullet();

    Bullet(int x, int y, int direction, char *skin);

    ~Bullet();

    Bullet &operator=(const Bullet &rhs);

    int X;
    int Y;
    char * skin;
    int direction;

};

#endif