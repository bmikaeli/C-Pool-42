#include "Zombie.hpp"

Zombie::Zombie(void) {
    std::cout << "zombie constructor called" << std::endl;
}

Zombie::~Zombie(void) {
    std::cout << "zombie destuctor called" << std::endl;
}

void Zombie::announce() {
    std::cout << "<" << this->name << " (" << this->type << ")> Braiiiiiiinnnssss..." << std::endl;
    return;
}

void Zombie::setName(std::string name) {
    this->name = name;
}

void Zombie::setType(std::string type) {
    this->type = type;
}

