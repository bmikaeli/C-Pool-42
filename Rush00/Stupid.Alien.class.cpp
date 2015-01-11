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

void Stupid::draw(WINDOW * win) {
    mvwprintw(win, this->Y, this->X, "X");
    mvwprintw(win, this->Y + 1, this->X - 1, "XXX");
}