#include "WindowRetro.class.hpp"

int main() {
    while (1) {
            WindowRetro *win = new WindowRetro();
            win->addAliens(5, 2, 1, 150);
            win->addAliens(20, 2, 1, 200);
            win->addAliens(35, 2, 1, 300);
            win->addAliens(50, 2, 1, 300);
            win->addAliens(65, 2, 1, 300);

            win->Play();
            delete win;
            break ;
    }
    return 0;
}

