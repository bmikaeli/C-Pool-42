#ifndef BOSS_ALIEN_CLASS_H
#define BOSS_ALIEN_CLASS_H

#include <unistd.h>
#include "AAlien.class.hpp"

class Boss : public AAlien {
public:
    Boss();

    Boss(int x, int y, int direction, int score);

    ~Boss();

    int checkColision(int x, int y);
    void drawDeath(WINDOW * win);
    void draw(WINDOW * win);
};

#endif
