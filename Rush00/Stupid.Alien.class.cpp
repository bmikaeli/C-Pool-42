#include "Stupid.Alien.class.hpp"

Stupid::Stupid(int x, int y, int direction, int scoreValue) {
    this->X = x;
    this->Y = y;
    this->scoreValue = scoreValue;
    this->direction = direction;
    this->bulletSkin = (char *) "X";
}

Stupid::Stupid() {
}

Stupid::~Stupid() {
}
