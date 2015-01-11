#include "WindowRetro.class.hpp"
int main() {
    WindowRetro *win = new WindowRetro();


    Stupid z(5, 2, 1, 100);
    Stupid a(25, 2, 1, 100);
    Stupid b(45, 2, 1, 100);
    Stupid c(65, 2, 1, 100);
    Stupid d(85, 2, 1, 100);
    Stupid e(15, 5, 1, 100);
    Stupid f(35, 5, 1, 100);
    Stupid i(55, 5, 1, 100);
    Stupid j(75, 5, 1, 100);
    win->addAliens(z);
    win->addAliens(a);
    win->addAliens(b);
    win->addAliens(c);
    win->addAliens(d);
    win->addAliens(e);
    win->addAliens(f);
    win->addAliens(i);
    win->addAliens(j);

    win->Play();
    delete win;
    return 0;
}

