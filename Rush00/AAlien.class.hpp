#ifndef ALIEN_CLASS_H
#define ALIEN_CLASS_H

#include <iostream>
#include <stdlib.h>
#include <curses.h>
#include <signal.h>

class AAlien {
public:
    virtual void takeDamage(int);

    AAlien();

    virtual ~AAlien();

    int hp;
    int scoreValue;
    char *bulletSkin;
    int X;
    int direction;
    int Y;
};

#endif
