#include "AAlien.class.hpp"
#include <unistd.h>

void AAlien::takeDamage() {
    this->hp -= 1;
}

AAlien::AAlien() {
}

AAlien::~AAlien() {
}


void AAlien::drawDeath(WINDOW * win) {
    wattron(win, COLOR_PAIR(2));
    mvwprintw(win, this->Y, this->X, "W");
    mvwprintw(win, this->Y + 1, this->X - 1, "WWW");
    wattron(win, COLOR_PAIR(1));
    wrefresh(win);
    usleep(10000);
}

void AAlien::draw(WINDOW * win) {
    mvwprintw(win, this->Y, this->X, "X");
    mvwprintw(win, this->Y + 1, this->X - 1, "XXX");
}

int AAlien::checkColision(int x, int y) {
    if ((this->X == x && this->Y == y) || (this->X - 1 == x && this->Y == y) || (this->X + 1 == x && this->Y == y)) {
        return 1;
    }
    else {
        return 0;
    }
}

AAlien &AAlien::operator=(AAlien &rhs) {
    this->hp = rhs.hp;
    this->scoreValue = rhs.scoreValue;
    this->bulletSkin = rhs.bulletSkin;
    this->X = rhs.X;
    this->direction = rhs.direction;
    this->size = rhs.size;
    this->Y = rhs.Y;
    return *this;
}
