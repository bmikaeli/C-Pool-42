#include "Stupid.Alien.class.hpp"

Stupid::Stupid(int x, int y, int direction, int scoreValue) {
    this->X = x;
    this->Y = y;
    this->scoreValue = scoreValue;
    this->direction = direction;
    std::cout << "Stupid alien is appeared" << std::endl;
}

Stupid::Stupid() {
    std::cout << "Stupid alien is appeared" << std::endl;
}

Stupid::~Stupid() {
    std::cout << "Stupid alien is dead" << std::endl;
}