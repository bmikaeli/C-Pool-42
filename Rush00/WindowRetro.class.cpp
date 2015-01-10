#include "WindowRetro.class.hpp"
#include <unistd.h>

WindowRetro::WindowRetro() : width(500), height(500) {
}

void WindowRetro::drawBorders(WINDOW * screen) {
    int x = this->width;
    int y = this->height;
    int i = 0;
    getmaxyx(screen, y, x);
    mvwprintw(screen, 0, 0, "+");
    mvwprintw(screen, y - 1, 0, "+");
    mvwprintw(screen, 0, x - 1, "+");
    mvwprintw(screen, y - 1, x - 1, "+");
    for (i = 1; i < (y - 1); i++) {
        mvwprintw(screen, i, 0, "|");
        mvwprintw(screen, i, x - 1, "|");
    }
    for (i = 1; i < (x - 1); i++) {
        mvwprintw(screen, 0, i, "-");
        mvwprintw(screen, y - 1, i, "-");
    }
}

void WindowRetro::handleKey(User *user, int key) {
    switch (key) {
        case KEY_RIGHT:
            if (user->X < this->width - 2)
                user->X++;
            break;
        case KEY_LEFT:
            if (user->X > 1)
                user->X--;
            break;
        case KEY_UP:
            if (user->Y > 1)
                user->Y--;
            break;
        case KEY_DOWN:
            if (user->Y < this->height - 2 - this->scoreSize)
                user->Y++;
            break;
        case KEY_BACKSPACE:
            this->fire();
        default:
            break;
    }
}

void WindowRetro::checkResize(void) {

    int new_x;
    int new_y;
    getmaxyx(stdscr, new_y, new_x);

    if (new_y != this->height || new_x != this->width) {
        this->width = new_x;
        this->height = new_y;
        wresize(this->plate, new_y - this->scoreSize, new_x);
        wresize(this->infos, this->scoreSize, new_x);
        mvwin(this->infos, new_y - this->scoreSize, 0);
        wclear(stdscr);
        wclear(this->plate);
        wclear(this->infos);
        this->drawBorders(this->plate);
        this->drawBorders(this->infos);
    }
}

void WindowRetro::fire() {
    int y = this->user->Y;
//    usleep(5000000);
    while(y-- >= 0)
    {
//        usleep(5000);
        wclear(this->plate);
        mvwprintw(this->plate, y, this->user->X, "I");
        wrefresh(this->plate);
    }
}

void WindowRetro::Play() {
    int i = 0;
    int direction = 1;
    while (1) {
        usleep(3000);
        this->checkResize();
        this->handleKey(this->user, getch());
        wclear(this->plate);
        this->drawBorders(this->plate);

        mvwprintw(this->infos, 0, 0, "Infos");
        mvwprintw(this->plate, alien->Y, alien->X, "X");
        mvwprintw(this->plate, this->user->Y, this->user->X, "0");
        mvwprintw(this->infos, 1, 5, "HP restant : ");
        mvwprintw(this->infos, 1, 18, "100");
        wrefresh(this->plate);
        wrefresh(this->infos);

        if (i % 10 == 0) {
            if (alien->X >= this->width) {
                alien->Y++;
                direction = -1;
            }
            if (alien->X <= 1) {
                direction = 1;
                alien->Y++;
            }
            alien->X += direction;
        }
        i++;
    }
}

WindowRetro::WindowRetro(int width, int height) : width(width), height(height), scoreSize(3) {
    std::cout << "New Window Created" << std::endl;
    this->user = new User();
    this->alien = new Stupid();

    initscr();
    start_color();
    curs_set(FALSE);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    this->plate = newwin(this->height - this->scoreSize, this->width, 0, 0);
    this->infos = newwin(this->scoreSize, this->width, this->height - this->scoreSize, 0);
    alien->X = 0;
    alien->Y = 0;

    this->Play();
    delwin(this->plate);
    delwin(this->infos);
}

WindowRetro::~WindowRetro() {
    endwin();
    std::cout << "New Window Destroyed" << std::endl;
}
