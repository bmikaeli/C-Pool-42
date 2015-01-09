#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant") {
    std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::~SuperMutant() {
    std::cout << "Aaargh ..." << std::endl;
}

void SuperMutant::takeDamage(int amount) {
    if (amount > 0) {
        this->setHP(this->getHP() - (amount - 3));
    }
}

SuperMutant &SuperMutant::operator=(SuperMutant const &rhs) {
    this->hp = rhs.getHP();
    this->type = rhs.getType();
    return *this;
}