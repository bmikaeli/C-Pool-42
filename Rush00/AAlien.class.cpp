#include "AAlien.class.hpp"

void AAlien::takeDamage(int amount) {
    this->hp -= amount;
}

AAlien::AAlien() {
}

AAlien::~AAlien() {
}


void AAlien::draw(WINDOW * win) {
    mvwprintw(win, this->Y, this->X, "X");
    mvwprintw(win, this->Y + 1, this->X - 1, "XXX");
}