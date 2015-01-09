#include "AWeapon.hpp"

AWeapon::AWeapon(const std::string &name, int apcost, int damage) {
    this->name = name;
    this->APcost = apcost;
    this->damage = damage;
}

AWeapon::~AWeapon() {
}

std::string AWeapon::getName() const {
    return this->name;
}

int AWeapon::getDamage() const {
    return this->damage;
}

int AWeapon::getAPCost() const {
    return this->APcost;
}

AWeapon &AWeapon::operator=(AWeapon const &rhs) {
    this->name = rhs.getName();
    this->damage = rhs.getDamage();
    this->APcost = rhs.getAPCost();
    return *this;
}