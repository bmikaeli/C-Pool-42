#include "Aweapon.class.hpp"

int Aweapon::getDamage() {
    return this->damage;
}

Aweapon::Aweapon(std::string name, int damage, char * skin) {
    this->name = name;
    this->damage = damage;
    this->skin = skin;
}

Aweapon::Aweapon() {

}

Aweapon::~Aweapon() {


}
const char * Aweapon::getName() {
    std::string s;
    std::stringstream out;
    out << this->name;
    s = out.str();
    const char *cstr = s.c_str();
    return cstr;
}