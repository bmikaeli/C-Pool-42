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

void Boss::draw(WINDOW * win) {
    mvwprintw(win, this->Y, this->X, "X");
    mvwprintw(win, this->Y + 1, this->X - 1, "XXXXXXXX");
}