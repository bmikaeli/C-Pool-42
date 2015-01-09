#include "RadScorpion.hpp"

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion") {
    std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion() {
    std::cout << "* SPROTCH *" << std::endl;
}

void RadScorpion::takeDamage(int amount) {
    if (amount > 0) {
        this->setHP(this->getHP() - (amount - 3));
    }
}

RadScorpion &RadScorpion::operator=(RadScorpion const &rhs) {
    this->hp = rhs.getHP();
    this->type = rhs.getType();
    return *this;
}