#include "HumanA.hpp"

void HumanA::attack() {
    std::cout << this->name << " attacks with his " << this->weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {
//    std::cout << "humanA constructor" << std::endl;
}

HumanA::~HumanA(void) {
//    std::cout << "humanA destructor" << std::endl;
}