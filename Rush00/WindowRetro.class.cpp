#include "WindowRetro.class.hpp"
#include <unistd.h>

WindowRetro::WindowRetro() : width(500), height(500){
}

void draw_borders(WINDOW *screen) {
    int x, y, i;
    getmaxyx(screen, y, x);
    // 4 corners
    mvwprintw(screen, 0, 0, "+");
    mvwprintw(screen, y - 1, 0, "+");
    mvwprintw(screen, 0, x - 1, "+");
    mvwprintw(screen, y - 1, x - 1, "+");
    // sides
    for (i = 1; i < (y - 1); i++) {
        mvwprintw(screen, i, 0, "|");
        mvwprintw(screen, i, x - 1, "|");
    }
    // top and bottom
    for (i = 1; i < (x - 1); i++) {
        mvwprintw(screen, 0, i, "-");
        mvwprintw(screen, y - 1, i, "-");
    }
}
void WindowRetro::handleKey(User * user, int key) {
    switch (key)
    {
        case KEY_RIGHT:
            if(user->X < this->width - 2)
                user->X++;
            break;
        case KEY_LEFT:
            if(user->X >  1)
                user->X--;
            break;
        case KEY_UP:
            if(user->Y > 1)
                user->Y--;
            break;
        case KEY_DOWN:
            if(user->Y < this->height - 1 - this->scoreSize)
                user->Y++;
            break;
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
        wresize(field, new_y - this->score_size, new_x);
        wresize(score, this->score_size, new_x);
        mvwin(score, new_y - this->score_size, 0);
        wclear(stdscr);
        wclear(field);
        wclear(score);
        draw_borders(field);
        draw_borders(score);
    }
}

WindowRetro::WindowRetro(int width, int height) : width(width), height(height){
    std::cout << "New Window Created" << std::endl;
    this->user = new User();
    this->alien = new Stupid();
    int parent_x, parent_y, new_x, new_y;
    int score_size = 3;
    initscr();
    start_color();
    curs_set(FALSE);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    WINDOW *field = newwin(parent_y - score_size, parent_x, 0, 0);
    WINDOW *score = newwin(score_size, parent_x, parent_y - score_size, 0);
    draw_borders(field);
    draw_borders(score);
    int x = parent_x /2;
    int y = parent_y / 2;
    alien->X = 10;
    alien->Y = 2;
    int i = 0;
    int direction = 1;
    while(1)
    {
        usleep(3000);
        getmaxyx(stdscr, new_y, new_x);
        this->checkResize();

        this->handleKey(this->user, getch());
        wclear(field);
        draw_borders(field);
        draw_borders(score);

        refresh();
        mvwprintw(score, 0, 0, "Infos");
        mvwprintw(field, alien->Y, alien->X, "X");
        mvwprintw(field, y, x, "0");
        mvwprintw(score, 1, 5, "HP restant : ");
        mvwprintw(score, 1, 18, "100");
        wrefresh(field);
        wrefresh(score);
        refresh();

        if(i % 10 == 0)
        {
            if(alien->X >= new_x) {
                alien->Y++;
                direction = -1;
            }
            if (alien->X <= 1)
            {
                direction = 1;
                alien->Y++;
            }
            alien->X += direction;
        }

        i++;
    }
    delwin(field);
    delwin(score);
}

WindowRetro::~WindowRetro() {
    endwin();
    std::cout << "New Window Destroyed" << std::endl;
}
