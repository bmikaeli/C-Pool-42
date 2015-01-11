#include "WindowRetro.class.hpp"

int main() {
    std::string input;


    while (1) {
        std::cout << "Game Over." << std::endl << "Play again ? [Y/N]" << std::endl;
        std::cin >> input;
        if (input == "Y" || input == "y") {
            WindowRetro *win = new WindowRetro();
            win->addAliens(5, 2, 1, 150);
            win->addAliens(20, 2, 1, 200);
            win->addAliens(35, 2, 1, 300);
            win->addAliens(50, 2, 1, 300);
            win->addAliens(65, 2, 1, 300);

            win->Play();
            delete win;
        }
        else if (input == "N" || input == "n") {
            break;
        }
    }
    return 0;
}

