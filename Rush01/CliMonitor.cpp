#include "CliMonitor.hpp"

void CliMonitor::drawBorders(WINDOW * screen) {
    int x = this->width;
    int y = this->height;
    int i = 0;
    getmaxyx(screen, y, x);
    mvwaddch(screen, 0, 0, ACS_ULCORNER);
    mvwaddch(screen, y - 1, 0, ACS_LLCORNER);
    mvwaddch(screen, 0, x - 1, ACS_URCORNER);
    mvwaddch(screen, y - 1, x - 1, ACS_LRCORNER);
    for (i = 1; i < (y - 1); i++) {
        mvwaddch(screen, i, 0, ACS_VLINE);
        mvwaddch(screen, i, x - 1, ACS_VLINE);
    }
    for (i = 1; i < (x - 1); i++) {
        mvwaddch(screen, 0, i, ACS_HLINE);
        mvwaddch(screen, y - 1, i, ACS_HLINE);
    }
}


void CliMonitor::checkResize(WINDOW * win) {
    int new_x;
    int new_y;
    getmaxyx(stdscr, new_y, new_x);
    if (new_y != this->height || new_x != this->width) {
        this->width = new_x;
        this->height = new_y;
        wresize(win, new_y, new_x);
    }
}

void CliMonitor::addModule(IMonitorModule *src) {
    this->modules.push_back(src);

    WINDOW *newone = newwin(50, 50, 1, 1);
    this->windows.push_back(newone);
}

void CliMonitor::launch(void) {
    std::cout << "size : " << this->windows.size() << std::endl;

    initscr();
    start_color();
    curs_set(FALSE);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

//    this->checkResize();
//
//
//
//

    std::list<WINDOW *>::iterator it = this->windows.begin();
    while (1) {
        this->checkResize(*it);
        mvwprintw(*it, 2, 2, "conard");
        wrefresh(*it);
        wclear(*it);
        usleep(20000);
//        drawBorders(*it);
//        printw("canard0",40, 50);
//        refresh();
//        clear();
//        this->drawBorders(*this->windows.begin());
//        wclear(*this->windows.begin());
//
////        for (it = this->windows.begin(); it != ite; it++) {
////            mvwprintw(*it, 1, 1, "canard");
////            wrefresh(*it);
////            wclear(*it);
////            printw("canard", 1, 1);
////            refresh();
////        }
    }
}

CliMonitor::CliMonitor() {
    this->height = 300;
    this->width = 300;
}

CliMonitor::~CliMonitor() {
    endwin();
}