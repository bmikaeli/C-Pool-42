#include "Peon.hpp"

Peon::Peon(std::string name) : Victim(name) {
    std::cout << "Zog zog." << std::endl;
}

Peon::~Peon() {
    std::cout << "Bleuark..." << std::endl;
}

void Peon::getPolymorphed() const {
    std::cout << this->getName() << " has been turned into a pink Pony !" << std::endl;

}

Peon &Peon::operator=(Peon const &rhs) {
    this->name = rhs.getName();
    return *this;
}