#include "WindowRetro.class.hpp"

int main() {
    WindowRetro *win = new WindowRetro();
    win->addAliens(20, 2, 1, 200);
    win->addAliens(5, 2, 1, 150);
    win->addAliens(10, 2, 1, 300);
    win->Play();
    delete win;
    return (0);
}

