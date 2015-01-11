#ifndef BOSS_ALIEN_CLASS_H
#define BOSS_ALIEN_CLASS_H

#include <unistd.h>
#include "AAlien.class.hpp"

class Boss : public AAlien {
public:
    Boss();

    Boss(Boss &src);

    Boss(int x, int y, int direction, int score);

    ~Boss();

    Boss &operator=(Boss const &rhs);


    int checkColision(int x, int y);

    void drawDeath(WINDOW *win);

    void draw(WINDOW *win);
};


#endif
