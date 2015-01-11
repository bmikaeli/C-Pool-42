#ifndef STUPID_ALIEN_CLASS_H
#define STUPID_ALIEN_CLASS_H

#include "AAlien.class.hpp"
#include "WindowRetro.class.hpp"

class Stupid : public AAlien {
public:
    Stupid();

    Stupid(Stupid &src);

    Stupid(int x, int y, int direction, int score);

    ~Stupid();

    Stupid &operator=(const Stupid &rhs);

    void draw(WINDOW *win);
};

#endif