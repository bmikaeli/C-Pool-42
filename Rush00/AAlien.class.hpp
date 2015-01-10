#ifndef ALIEN_CLASS_H
#define ALIEN_CLASS_H

#include <iostream>

class AAlien {
public:
    virtual void takeDamage(int);

    AAlien();

    ~AAlien();

    int hp;
    int X;
    int Y;
};

#endif