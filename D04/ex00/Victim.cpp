#include "Victim.hpp"

Victim::Victim(std::string name) : name(name) {
    std::cout << "Some random victim called " << this->name << " just popped !" << std::endl;
}

Victim::~Victim() {
    std::cout << "Victim " << this->name << " just died for no apparent reason !" << std::endl;
}

std::ostream &operator<<(std::ostream &o, const Victim &rhs) {
    o << "I'm " << rhs.getName() << ", and I like otters !" << std::endl;
    return o;
}

void Victim::getPolymorphed() const {
    std::cout << this->getName() << " has been turned into a cute little sheep !" << std::endl;

}

std::string Victim::getName() const {
    return this->name;
}

void Victim::setName(std::string name) {
    this->name = name;
};

Victim &Victim::operator=(Victim const &rhs) {
    this->name = rhs.getName();
    return *this;
}