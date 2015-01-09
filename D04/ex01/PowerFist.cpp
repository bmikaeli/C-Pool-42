#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50) {
}

PowerFist::~PowerFist() {

}

void PowerFist::attack() const {
    std::cout << "* pschhh... SBAM! *" << std::endl;
}

PowerFist &PowerFist::operator=(PowerFist const &rhs) {
    this->name = rhs.getName();
    this->damage = rhs.getDamage();
    this->APcost = rhs.getAPCost();
    return *this;
}