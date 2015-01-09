#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title) : name(name), title(title) {
    std::cout << this->name << ", " << this->title << ", is born !" << std::endl;
}

Sorcerer::~Sorcerer() {
    std::cout << this->name << ", " << this->title << ", is dead. Consequences will never be the same !" << std::endl;

}

std::ostream &operator<<(std::ostream &o, const Sorcerer &rhs) {
    o << "I am " << rhs.getName() << ", " << rhs.getTitle() << ", and I like ponies !" << std::endl;
    return o;
}

void Sorcerer::polymorph(const Victim &src) {
    src.getPolymorphed();
}

std::string Sorcerer::getName() const {
    return this->name;
}

//
std::string Sorcerer::getTitle() const {
    return this->title;
}

void Sorcerer::setTitle(std::string title) {
    this->title = title;
}

void Sorcerer::setName(std::string name) {
    this->name = name;
}

Sorcerer &Sorcerer::operator=(Sorcerer const &rhs) {
    this->name = rhs.getName();
    this->title = rhs.getTitle();
    return *this;
}