#include "User.class.hpp"

void User::takeDamage(int amount) {
    this->hp -= amount;
}

void User::attack(AAlien &target) {
    target.takeDamage();
}

const char *User::getWeapon() const {
    std::string s;
    std::stringstream out;
    out << this->weapon;
    s = out.str();
    const char *cstr = s.c_str();
    return cstr;
}

void User::addWeapon(Aweapon &src) {
    int i = 0;
    int j = 0;
    Aweapon *newWeapon = new Aweapon[this->nbWeapon + 1];
    while (i < this->nbWeapon) {
        if (this->weapon[i].getDamage() != 0) {
            newWeapon[j] = this->weapon[i];
            j++;
        }
        i++;
    }
    newWeapon[i] = src;
    this->nbWeapon++;
    this->weapon = newWeapon;
}

void User::changeWeapon() {
    this->currentWeaponIndex = (this->currentWeaponIndex + 1) > this->nbWeapon ? 0 : this->currentWeaponIndex + 1;
}

User::User() {
    this->X = 1;
    this->Y = 1;
    this->hp = 100;
    this->lives = 3;
    this->score = 0;
}

const char *User::getLives() {
    std::string s;
    std::stringstream out;
    out << this->lives;
    s = out.str();
    const char *cstr = s.c_str();
    return cstr;
}

const char *User::getScore() {
    std::string s;
    std::stringstream out;
    out << this->score;
    s = out.str();
    const char *cstr = s.c_str();
    return cstr;
}
