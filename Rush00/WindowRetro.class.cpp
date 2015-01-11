#include "WindowRetro.class.hpp"

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

int WindowRetro::handleKey(User *user, int key) {
    switch (key) {
        case KEY_RIGHT:
            if (user->X < this->width - 2)
                user->X++;
            break;
        case KEY_LEFT:
            if (user->X > 2)
                user->X--;
            break;
        case KEY_UP:
            if (user->Y > this->height / 2)
                user->Y--;
            break;
        case KEY_DOWN:
            if (user->Y < this->height - 3 - this->scoreSize)
                user->Y++;
            break;
        case KEY_NPAGE:
            return 1;
        case ' ':
            this->addBullet(this->user->X, this->user->Y, 1);
        case KEY_PPAGE:
            this->user->changeWeapon();
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

int WindowRetro::drawBullets() {
    if (this->nbBullets >= 1) {
        for (int i = 0; i < this->nbBullets; i++) {
            if (this->bullets[i].Y >= 0) {
                this->bullets[i].Y -= this->bullets[i].direction;
                mvwprintw(this->plate, this->bullets[i].Y, this->bullets[i].X, "|");
                int colision = this->checkColisions(this->bullets[i].X, this->bullets[i].Y);
                if (colision) {
                    if (colision == 1) {
                        return 1;
                    }
                    else if (colision == 2) {
                        this->deleteBullets(i);
                    }
                }
            }
            else {
                this->deleteBullets(i);
            }
        }
    }
    return 0;
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

void WindowRetro::deleteBullets(int bulletIndex) {
    Bullet *newone = new Bullet[this->nbBullets - 1];
    int i = 0;
    int j = 0;
    while (i < this->nbBullets) {
        if (i != bulletIndex) {
            newone[j] = this->bullets[i];
            j++;
        }
        i++;
    }
    this->nbBullets--;
    this->bullets = newone;
}

int WindowRetro::checkColisions(int x, int y) {
    if (this->nbAliens >= 1) {
        for (int i = 0; i < this->nbAliens; i++) {
            if ((this->aliens[i].X == x && this->aliens[i].Y == y) || (this->aliens[i].X - 1 == x && this->aliens[i].Y == y) || (this->aliens[i].X + 1 == x && this->aliens[i].Y == y)) {
                this->user->score += this->aliens[i].scoreValue;
                this->deleteAlien(i);
                return 2;
            }
        }
    }
    if ((this->user->X == x && this->user->Y == y) || (this->user->X - 1 == x && this->user->Y == y) || (this->user->X + 1 == x && this->user->Y == y)) {
        {
            this->user->lives -= 1;
            if (this->user->lives < 0) {
                return 1;
            }
        }
    }
    return 0;
}

int WindowRetro::checkHumanColisions(int x, int y) {
    for (int i = 0; i < this->nbAliens; i++) {
        if ((this->aliens[i].X == x && this->aliens[i].Y == y) || (this->aliens[i].X - 1 == x && this->aliens[i].Y == y) || (this->aliens[i].X + 1 == x && this->aliens[i].Y == y)) {
            this->user->score += this->aliens[i].scoreValue;
            this->deleteAlien(i);
            return 1;
        }
        else
            return 0;
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
            mvwprintw(this->plate, this->aliens[i].Y + 1, this->aliens[i].X - 1, "XXX");
        }
    }
}

void WindowRetro::moveAliens() {
    if (this->nbAliens >= 1) {
        for (int i = 0; i < this->nbAliens; i++) {
            if (aliens[i].X >= this->width - 2) {
                aliens[i].Y += 2;
                aliens[i].direction = -1;
            }
            if (aliens[i].X <= 2) {
                aliens[i].direction = 1;
                aliens[i].Y += 2;
            }
            aliens[i].X += aliens[i].direction;
        }
    }
}

void WindowRetro::aliensAttack(int randomNumber) {
    std::srand(time(NULL));
    if (this->nbAliens >= 1) {
        for (int i = 0; i < this->nbAliens; i++) {
            if ((randomNumber + i * 11 + rand()) % 50 == 0) {
                this->addBullet(this->aliens[i].X, this->aliens[i].Y, -1);
            }
        }
    }
}

void WindowRetro::Play() {
    int i = 0;
    int direction = 1;
    int tmp = 0;
    int startx = 0;
    int starty = 0;
    while (1) {
        usleep(20000);

        if (nbAliens < 6) {
            int tmp = 6 - nbAliens;
            for (int g = 0; g < tmp; g++) {
                if (this->aliens[nbAliens].X < 4)
                    this->addAliens(12, 2, 1, 150);
                else
                    this->addAliens(2, 2, 1, 150);
            }
        }
        int z = this->checkHumanColisions(this->user->X, this->user->Y);
        if (z == 1)
            break;
        this->checkResize();
        if (this->handleKey(this->user, getch()) == 1) {
            break;
        }
        if (this->drawBullets() == 1) {
            break;
        }
        this->drawBorders(this->plate);
        this->drawBorders(this->infos);
        this->drawAliens();
        mvwprintw(this->infos, 0, 0, "Infos");
        mvwprintw(this->plate, this->user->Y, this->user->X, "0");
        mvwprintw(this->plate, this->user->Y + 1, this->user->X - 1, "000");
        mvwprintw(this->infos, 1, 2, "lives : ");
        mvwprintw(this->infos, 1, 10, this->user->getLives());
        mvwprintw(this->infos, 1, 25, "Score : ");
        mvwprintw(this->infos, 1, 32, this->user->getScore());
        mvwprintw(this->infos, 1, 45, "Weapon :");
        mvwprintw(this->infos, 1, 55, "Rocket Launcher");

        if (i % 10 == 0) {
            this->moveAliens();
        }
        this->aliensAttack(i);
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
    this->user->Y = 10;
    RocketLauncher a;
    Laser b;
    this->user->addWeapon(a);
    this->user->addWeapon(b);

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
