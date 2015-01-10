#ifndef WindowRetro_CLASS_H
#define WindowRetro_CLASS_H

#include <iostream>
#include <stdlib.h>
#include <curses.h>
#include <signal.h>
#include "User.class.hpp"
#include "AAlien.class.hpp"
#include "Bullet.Weapon.class.hpp"
#include "Stupid.Alien.class.hpp"

class WindowRetro {
public:
    WindowRetro();

    WindowRetro(int width, int height);

    ~WindowRetro();

    void handleKey(User *user, int key);

private:
    void fire();

    void deleteAlien(int i);

    void drawAliens();

    void moveAliens();

    void addAliens(int x, int y, int direction, int scoreValue);

    void drawBorders(WINDOW *screen);

    void Play();

    void drawBullets();

    void addBullet(int x, int y, int direction);

    void checkResize();

    void checkColisions(int x, int y);

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