#include "Aweapon.class.hpp"
int Aweapon::getDamage() {
    return this->damage;
}

Aweapon::Aweapon(std::string name, int damage) {
    this->name = name;
    this->damage = damage;
}

Aweapon::Aweapon() {

}

Aweapon::~Aweapon() {

}