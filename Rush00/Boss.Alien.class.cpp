#include "Boss.Alien.class.hpp"

Boss::Boss(int x, int y, int direction, int scoreValue) {
    this->X = x;
    this->Y = y;
    this->size = 5;
    this->hp = 5;
    this->scoreValue = scoreValue;
    this->direction = direction;
    this->bulletSkin = (char *) "U";
}

Boss::Boss() {
}

Boss::~Boss() {
}

void Boss::draw(WINDOW * win) {
    mvwprintw(win, this->Y - 1, this->X - 3, "/X\\ /X\\");
    mvwprintw(win, this->Y, this->X - 1, "/X\\");
    mvwprintw(win, this->Y + 1, this->X - 1, "---");
}

void Boss::drawDeath(WINDOW * win) {
    wattron(win, COLOR_PAIR(2));
    mvwprintw(win, this->Y - 2, this->X - 3, "/X\\ /X\\");
    mvwprintw(win, this->Y - 1, this->X - 1, "/X\\");
    mvwprintw(win, this->Y, this->X - 1, "---");
    wattron(win, COLOR_PAIR(1));
    wrefresh(win);
    usleep(10000);
}

int Boss::checkColision(int x, int y) {
    if ((this->X - 3 == x && this->Y - 2 == y)
            || (this->X - 2 == x && this->Y - 2 == y)
            || (this->X - 1 == x && this->Y - 2 == y)
            || (this->X == x && this->Y - 2 == y)
            || (this->X + 1 == x && this->Y - 2 == y)
            || (this->X + 2 == x && this->Y - 2 == y)
            || (this->X + 3 == x && this->Y - 2 == y)
            || (this->X - 1 == x && this->Y == y)
            || (this->X == x && this->Y == y)
            || (this->X + 1 == x && this->Y == y)) {
        return 1;
    }
    else {
        return 0;
    }
}
