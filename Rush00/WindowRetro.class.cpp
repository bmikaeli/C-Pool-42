#include "WindowRetro.class.hpp"

void WindowRetro::drawBorders(WINDOW * screen) {
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
            if (user->Y > this->height / 2) {
                user->Y--;
            }
            break;
        case KEY_DOWN:
            if (user->Y < this->height - 3 - this->scoreSize) {
                user->Y++;
            }
            break;
        case KEY_HOME:
            this->user->changeWeapon();
            break;
        case KEY_NPAGE:
            return 1;
        case ' ':
            this->addBullet(this->user->X, this->user->Y, 1, this->user->weapon[this->user->currentWeaponIndex].skin);
        default:
            break;
    }
    return 0;
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
                if ((this->user->weapon[this->user->currentWeaponIndex].getDamage() == 50) && (this->bullets[i].direction == 1))
                    wattron(this->plate, COLOR_PAIR(3));
                else if ((this->user->weapon[this->user->currentWeaponIndex].getDamage() == 30) && (this->bullets[i].direction == 1))
                    wattron(this->plate, COLOR_PAIR(2));

                mvwprintw(this->plate, this->bullets[i].Y, this->bullets[i].X, this->bullets[i].skin);
                wattron(this->plate, COLOR_PAIR(1));
                int colision = this->checkColisions(this->bullets[i].X, this->bullets[i].Y, this->bullets->direction);
                if (colision) {
                    wattron(this->plate, COLOR_PAIR(2));
                    mvwprintw(this->plate, this->bullets[i].Y, this->bullets[i].X, "W");
                    mvwprintw(this->plate, this->bullets[i].Y + 1, this->bullets[i].X - 1, "WWW");
                    this->deleteBullets(i);
                    wattron(this->plate, COLOR_PAIR(1));
                    this->drawBorders(this->plate);
                    wrefresh(this->plate);
                    usleep(10000);
                    if (colision == 1) {
                        return 1;
                    }
                }

            }
            else
                this->deleteBullets(i);
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

int WindowRetro::checkColisions(int x, int y, int direction) {
    if (this->nbAliens >= 1) {
        for (int i = 0; i < this->nbAliens; i++) {
            if (direction == -1) {
                if ((this->aliens[i].X == x && this->aliens[i].Y == y) || (this->aliens[i].X - 1 == x && this->aliens[i].Y == y) || (this->aliens[i].X + 1 == x && this->aliens[i].Y == y)) {
                    this->user->score += this->aliens[i].scoreValue;
                    this->deleteAlien(i);
                    return 2;
                }
            }
        }
    }
    if ((this->user->X == x && this->user->Y == y) || (this->user->X - 1 == x && this->user->Y == y) || (this->user->X + 1 == x && this->user->Y == y)) {
        {
            wattron(this->plate, COLOR_PAIR(2));
            mvwprintw(this->plate, this->user->Y, this->user->X, "0");
            mvwprintw(this->plate, this->user->Y + 1, this->user->X - 1, "000");
            wattron(this->plate, COLOR_PAIR(1));
            this->drawBorders(this->plate);
            wrefresh(this->plate);
            usleep(100000);
            this->user->lives -= 1;
            if (this->user->lives < 1) {
                return 1;
            }
        }
    }
    return 0;
}


int WindowRetro::checkHumanColisions(int x, int y) {
    for (int i = 0; i < this->nbAliens; i++) {
        if ((this->aliens[i].X == x && this->aliens[i].Y == y) || (this->aliens[i].X - 1 == x && this->aliens[i].Y == y) || (this->aliens[i].X + 1 == x && this->aliens[i].Y == y) || (this->aliens[i].X == x && this->aliens[i].Y - 1 == y) || (this->aliens[i].X == x && this->aliens[i].Y == y - 1)) {
            this->deleteAlien(i);
            return 2;
        }
    }
    return 0;
}

void WindowRetro::addBullet(int x, int y, int direction, char *skin) {

    Bullet *newone = new Bullet[this->nbBullets + 1];
    int i = 0;
    while (i < this->nbBullets) {
        newone[i] = this->bullets[i];
        i++;
    }
    newone[i] = Bullet(x, y, direction, skin);
    this->nbBullets++;
    this->bullets = newone;
}

void WindowRetro::drawAliens() {
    if (this->nbAliens >= 1) {
        for (int i = 0; i < this->nbAliens; i++) {
            mvwprintw(this->plate, this->aliens[i].Y, this->aliens[i].X, "X");
            mvwprintw(this->plate, this->aliens[i].Y + 1, this->aliens[i].X - 1, "XXX");
        }
    }
}

void WindowRetro::moveAliens() {
    if (this->nbAliens >= 1) {
        for (int i = 0; i < this->nbAliens; i++) {
            if (aliens[i].X >= this->width - 2) {
                for (int z = 0; z < this->nbAliens; z++) {

                    aliens[z].Y += 2;
                    aliens[z].direction = -1;
                }

            }
            if (aliens[i].X <= 2) {
                for (int j = 0; j < this->nbAliens; j++) {
                    aliens[j].direction = 1;
                    aliens[j].Y += 2;
                }
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
                this->addBullet(this->aliens[i].X, this->aliens[i].Y, -1, this->aliens[i].bulletSkin);
            }
        }
    }
}

void WindowRetro::Play() {
    int i = 0;
    this->checkResize();
    this->user->X = this->width / 2;
    this->user->Y = this->height / 4 * 3;
    while (1) {

        usleep(20000);

        if (nbAliens == 0) {
            this->user->win = 1;
            break;
        }
        int z = this->checkHumanColisions(this->user->X, this->user->Y);
        if (z == 2) {
            break;
        }
        if (this->handleKey(this->user, getch()) == 1) {
            this->user->win = 0;
            break;
        }
        if (this->drawBullets() == 1) {
            this->user->lives = 0;
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
        mvwprintw(this->infos, 1, 55, this->user->weapon[this->user->currentWeaponIndex].getName());

        if (i % 10 == 0) {
            this->moveAliens();
        }
        this->checkResize();
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

    RocketLauncher a;
    Laser b;

    this->user->addWeapon(a);
    this->user->addWeapon(b);
    this->user->currentWeaponIndex = 0;

    initscr();
    start_color();
    curs_set(FALSE);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);

    this->plate = newwin(this->height - this->scoreSize, this->width, 0, 0);
    this->infos = newwin(this->scoreSize, this->width, this->height - this->scoreSize, 0);
}

WindowRetro::~WindowRetro() {
    delwin(this->plate);
    delwin(this->infos);
    endwin();
    if(this->user->lives == 0)
        std::cout << "Your dead, Try Again!" << std::endl;
    else if(this->user->win == 0)
        std::cout << "You quit...!" << std::endl;
    else
        std::cout << "You win, Congratulations!" << std::endl;
}
