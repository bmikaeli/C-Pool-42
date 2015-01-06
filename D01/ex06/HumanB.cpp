#include "HumanB.hpp"

void HumanB::attack() {
    std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}

HumanB::HumanB(std::string name) : name(name) {
//    std::cout << "humanB constructor" << std::endl;
}

HumanB::~HumanB(void) {
//    std::cout << "humanB destructor" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon){
    this->weapon = &weapon;
}

