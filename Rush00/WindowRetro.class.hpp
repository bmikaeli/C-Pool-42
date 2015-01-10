#ifndef WindowRetro_CLASS_H
#define WindowRetro_CLASS_H

#include <iostream>
#include <stdlib.h>
#include <curses.h>
#include <signal.h>
#include "User.class.hpp"
#include "AAlien.class.hpp"
#include "Stupid.Alien.class.hpp"

class WindowRetro {
public:
    WindowRetro();

    WindowRetro(int width, int height);

    ~WindowRetro();

    void handleKey(User *user, int key);

private:
    int width;
    int height;
    int scoreSize;
    User *user;
    AAlien *alien;

    void checkResize();

    WINDOW *plate;
    WINDOW *infos;

    void fire();

    void drawBorders(WINDOW *screen);

    void Play();
};

#endif