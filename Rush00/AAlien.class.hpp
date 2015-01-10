#ifndef ALIEN_CLASS_H
#define ALIEN_CLASS_H

#include <iostream>
#include <stdlib.h>
#include <curses.h>
#include <signal.h>

class AAlien {
public:
    virtual void takeDamage(int);

    virtual void draw(WINDOW *plate, int Y, int x) const;

    AAlien();

    virtual ~AAlien();

    int hp;
    int scoreValue;
    int X;
    int direction;
    int Y;
};

#endif