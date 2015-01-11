#include "WindowRetro.class.hpp"

int main() {
    std::string input;
    std::size_t found;
    std::size_t found2;
    std::size_t found3;
    std::size_t found4;


    while (1) {
        std::cout << "Game Over." << std::endl << "Play again ? [Y/N]" << std::endl;
        std::cin >> input;
        found = input.find("Y");
        found2 = input.find("y");
        found3 = input.find("N");
        found4 = input.find("n");
        if (found != std::string::npos || found2 != std::string::npos) {
            WindowRetro *win = new WindowRetro();
            win->addAliens(5, 2, 1, 150);
            win->addAliens(20, 2, 1, 200);
            win->addAliens(35, 2, 1, 300);
            win->addAliens(50, 2, 1, 300);
            win->addAliens(65, 2, 1, 300);

            win->Play();
            delete win;
        }
        else if (found3 != std::string::npos || found4 != std::string::npos) {
            break;
        }
    }
    return 0;
}

