#include "AAlien.class.hpp"

void AAlien::takeDamage(int amount) {
    this->hp -= amount;
}

AAlien::AAlien() {
    std::cout << "A alien abstract has appared" << std::endl;
}

AAlien::~AAlien() {
    std::cout << "A alien abstract hase disapread" << std::endl;
}
