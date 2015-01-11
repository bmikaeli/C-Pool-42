#include "Boss.Alien.class.hpp"

Boss::Boss(int x, int y, int direction, int scoreValue) {
    this->X = x;
    this->Y = y;
    this->scoreValue = scoreValue;
    this->direction = direction;
    this->bulletSkin = (char *) "U";
}

Boss::Boss() {
}

Boss::~Boss() {
}
