#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
    this->type = type;
//    std::cout << "weapon constructor" << std::endl;
    return;
}

Weapon::~Weapon(void) {
//    std::cout << "weapon destructor" << std::endl;
    return;
}

void Weapon::setType(std::string type) {
    this->type = type;
}

const std::string &Weapon::getType() {
    const std::string &type = this->type;
    return type;
}