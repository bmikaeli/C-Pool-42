#include "User.class.hpp"

void User::takeDamage(int amount) {
    this->hp -= amount;
}

void User::attack(AAlien &target) {
    target.takeDamage(this->weapon->getDamage());
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
    Aweapon *newWeapon = new Aweapon[this->nbWeapon + 1];
    int i = 0;
    while (i < this->nbWeapon) {
        newWeapon[i] = this->weapon[i];
        i++;
    }
    newWeapon[i] = src;
    this->nbWeapon++;
    this->weapon = newWeapon;

}

void User::changeWeapon() {
//    this->currentWeaponIndex = (this->currentWeaponIndex  + 1) > this->nbWeapon ? 0 : this->currentWeaponIndex + 1;
}
User::User() {
    this->X = 1;
    this->Y = 1;
    this->hp = 100;
    this->lives = 3;
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