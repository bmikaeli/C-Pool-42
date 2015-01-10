#include "WindowRetro.class.hpp"

void WindowRetro::drawBorders(WINDOW *screen) {
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

int WindowRetro::handleKey(User *user, int key) {
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
        case KEY_NPAGE:
            return 1;
        case ' ':
            this->addBullet(this->user->X, this->user->Y, 1);
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
        this->drawBorders(this->plate);
        this->drawBorders(this->infos);
    }
}

void WindowRetro::drawBullets() {
    if (this->nbBullets >= 1) {
        for (int i = 0; i < this->nbBullets; i++) {
            if (this->bullets[i].Y >= 0) {
                this->bullets[i].Y--;
                mvwprintw(this->plate, this->bullets[i].Y, this->bullets[i].X, "|");
                this->checkColisions(this->bullets[i].X, this->bullets[i].Y);
            }
        }
    }
}

void WindowRetro::deleteAlien(int alienIndex) {
    AAlien *newaliens = new AAlien[this->nbAliens - 1];
    int i = 0;
    int j = 0;
    while (i < this->nbAliens) {
        if (i != alienIndex) {
            newaliens[j] = this->aliens[i];
            j++;
        }
        i++;
    }
    this->nbAliens--;
    this->aliens = newaliens;
}

void WindowRetro::checkColisions(int x, int y) {
    if (this->nbAliens >= 1) {
        for (int i = 0; i < this->nbAliens; i++) {
            if (this->aliens[i].X == x && this->aliens[i].Y == y) {
                this->user->score += this->aliens[i].scoreValue;
                this->deleteAlien(i);
            }
        }
    }
}

void WindowRetro::addBullet(int x, int y, int direction) {

    Bullet *newone = new Bullet[this->nbBullets + 1];
    int i = 0;
    while (i < this->nbBullets) {
        newone[i] = this->bullets[i];
        i++;
    }
    newone[i] = Bullet(x, y, direction);
    this->nbBullets++;
    this->bullets = newone;
}

void WindowRetro::drawAliens() {
    if (this->nbAliens >= 1) {
        for (int i = 0; i < this->nbAliens; i++) {
            this->aliens[i].draw(this->plate, this->aliens[i].Y, this->aliens[i].X);
            mvwprintw(this->plate, this->aliens[i].Y, this->aliens[i].X, "X");
            mvwprintw(this->plate, this->aliens[i].Y + 1, this->aliens[i].X + 1, "X");
            mvwprintw(this->plate, this->aliens[i].Y + 1, this->aliens[i].X - 1, "X");
            mvwprintw(this->plate, this->aliens[i].Y + 1, this->aliens[i].X, "X");
        }
    }
}

void WindowRetro::moveAliens() {
    if (this->nbAliens >= 1) {
        for (int i = 0; i < this->nbAliens; i++) {
            if (aliens[i].X >= this->width) {
                aliens[i].Y++;
                aliens[i].direction = -1;
            }
            if (aliens[i].X <= 1) {
                aliens[i].direction = 1;
                aliens[i].Y++;
            }
            aliens[i].X += aliens[i].direction;
        }
    }
}

void WindowRetro::Play() {
    int i = 0;
    int direction = 1;
    while (1) {
        usleep(30000);

        this->checkResize();
        if (this->handleKey(this->user, getch()) == 1) {
            break;
        }
        this->drawBorders(this->plate);
        this->drawBorders(this->infos);
        this->drawBullets();
        this->drawAliens();

        mvwprintw(this->infos, 0, 0, "Infos");
        mvwprintw(this->plate, this->user->Y, this->user->X, "0");
        mvwprintw(this->infos, 1, 2, "HP restant : ");
        mvwprintw(this->infos, 1, 14, "100");
        mvwprintw(this->infos, 1, 25, "Score : ");
        mvwprintw(this->infos, 1, 32, "0");
        mvwprintw(this->infos, 1, 45, "Weapon :");
        mvwprintw(this->infos, 1, 55, "Rocket Launcher");


        if (i % 10 == 0) {
            this->moveAliens();
        }
        wrefresh(this->infos);
        wrefresh(this->plate);
        wclear(this->plate);
        wclear(this->infos);
        i++;
    }
}

void WindowRetro::addAliens(int x, int y, int direction, int scoreValue) {
    AAlien *newaliens = new AAlien[this->nbAliens + 1];
    int i = 0;
    while (i < this->nbAliens) {
        newaliens[i] = this->aliens[i];
        i++;
    }
    newaliens[i] = Stupid(x, y, direction, scoreValue);
    this->nbAliens++;
    this->aliens = newaliens;
}

WindowRetro::WindowRetro() {
    this->scoreSize = 3;
    this->height = 600;
    this->width = 300;
    this->nbBullets = 0;
    this->nbAliens = 0;
    this->user = new User();
    this->user->X = 50;

    initscr();
    start_color();
    curs_set(FALSE);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    this->plate = newwin(this->height - this->scoreSize, this->width, 0, 0);
    this->infos = newwin(this->scoreSize, this->width, this->height - this->scoreSize, 0);
}

WindowRetro::~WindowRetro() {
    delwin(this->plate);
    delwin(this->infos);
    endwin();
}
