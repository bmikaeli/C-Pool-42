#ifndef WindowRetro_CLASS_H
#define WindowRetro_CLASS_H

#include <iostream>
#include <stdlib.h>
#include <curses.h>
#include <signal.h>
#include <string>
#include "User.class.hpp"
#include <unistd.h>
#include "AAlien.class.hpp"
#include "Bullet.Weapon.class.hpp"
#include <cstdlib>
#include "Laser.Weapon.class.hpp"
#include "RocketLauncher.Weapon.class.hpp"
#include "Stupid.Alien.class.hpp"
#include "Boss.Alien.class.hpp"

class WindowRetro {
public:
    WindowRetro();

    ~WindowRetro();

    int handleKey(User *user, int key);

    void addAliens(int x, int y, int direction, int scoreValue);

    void addBoss(int x, int y, int direction, int scoreValue);

    void Play();

private:

    void fire();

    void aliensAttack(int random);

    void deleteAlien(int i);

    void deleteBullets(int i);

    void drawAliens();

    void moveAliens();

    void drawBorders(WINDOW *screen);

    int drawBullets();

    void addBullet(int x, int y, int direction, char *skin);

    void checkResize();

    int checkColisions(int x, int y, int direction);

    int checkHumanColisions(int x, int y);

    int width;
    int height;
    int scoreSize;
    User *user;
    AAlien *aliens;
    Bullet *bullets;
    int nbBullets;
    int nbAliens;
    WINDOW *plate;
    WINDOW *infos;
};

#endif
