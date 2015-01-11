#ifndef BOSS_ALIEN_CLASS_H
#define BOSS_ALIEN_CLASS_H

#include "AAlien.class.hpp"

class Boss : public AAlien {
public:
    Boss();

    Boss(int x, int y, int direction, int score);

    ~Boss();

    void draw();
};

#endif