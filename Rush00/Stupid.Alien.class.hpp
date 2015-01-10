#ifndef STUPID_ALIEN_CLASS_H
#define STUPID_ALIEN_CLASS_H

#include "AAlien.class.hpp"

class Stupid : public AAlien {
public:
    Stupid();

    Stupid(int x, int y, int direction, int score);

    ~Stupid();

};

#endif