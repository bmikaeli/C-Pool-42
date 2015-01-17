#include "CliMonitor.hpp"

void CliMonitor::drawBorders() {

//
    std::list<WINDOW *>::iterator it;
    std::list<WINDOW *>::iterator ite;

    ite = this->windows.end();
    for (it = this->windows.begin(); it++ != ite; it++) {
        int x = this->width;
        int y = this->height;
        int i = 0;
        getmaxyx(*it, y, x);
        mvwaddch(*it, 0, 0, ACS_ULCORNER);
        mvwaddch(*it, y - 1, 0, ACS_LLCORNER);
        mvwaddch(*it, 0, x - 1, ACS_URCORNER);
        mvwaddch(*it, y - 1, x - 1, ACS_LRCORNER);
        for (i = 1; i < (y - 1); i++) {
            mvwaddch(*it, i, 0, ACS_VLINE);
            mvwaddch(*it, i, x - 1, ACS_VLINE);
        }
        for (i = 1; i < (x - 1); i++) {
            mvwaddch(*it, 0, i, ACS_HLINE);
            mvwaddch(*it, y - 1, i, ACS_HLINE);
        }
    }
}

void CliMonitor::checkResize(void) {
    int new_x;
    int new_y;
    getmaxyx(stdscr, new_y, new_x);
    if (new_y != this->height || new_x != this->width) {
        this->width = new_x;
        this->height = new_y;
        std::list<WINDOW *>::iterator it;
        std::list<WINDOW *>::iterator ite;

        ite = this->windows.end();

        int i = 1;
        for (it = this->windows.begin(); it++ != ite; it++) {
            wresize(*it, new_y / this->windows.size() * i, new_x);
            i++;
        }
        wclear(stdscr);
    }
}

void CliMonitor::addModule(IMonitorModule *src) {
    this->modules.push_back(src);

    WINDOW *newone = newwin(this->height / 3, this->width, 0, 0);
    this->windows.push_back(newone);
}

CliMonitor::CliMonitor() {
    initscr();
    start_color();
    curs_set(FALSE);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    this->height = 300;
    this->width = 300;

//    *this->modules.begin() = newwin(this->height, this->width, 0, 0);
    this->checkResize();
    this->drawBorders();

//    while(1)
//    {
//        mvwprintw(*this->modules.begin(), 1 , 1, "canard");
//        wrefresh(*this->modules.begin());
////        drawBorders(this->name);
////        wclear(this->name);
//    }
}

CliMonitor::~CliMonitor() {
    endwin();
}