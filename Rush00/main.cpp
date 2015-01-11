#include "WindowRetro.class.hpp"

int main() {
    WindowRetro *win = new WindowRetro();

    win->addAliens(5, 2, 1, 150);
    win->addAliens(25, 2, 1, 200);
    win->addAliens(45, 2, 1, 300);
    win->addAliens(65, 2, 1, 300);
    win->addAliens(85, 2, 1, 300);
    win->addAliens(15, 5, 1, 300);
    win->addAliens(35, 5, 1, 300);
    win->addAliens(55, 5, 1, 300);
    win->addAliens(75, 5, 1, 300);

    win->Play();
    delete win;
    return 0;
}

