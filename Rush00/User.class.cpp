#include "User.class.hpp"
void User::takeDamage(int amount) {
    this->hp -= amount;
}
void User::attack(AAlien & target) {
    target.takeDamage(this->weapon->getDamage());
}
Aweapon* User::getWeapon() const {
    return this->weapon;
}

User::User() {
    this->X = 1;
    this->Y = 1;
    this->hp = 100;
    this->lives = 3;
    std::cout << "User constructed" << std::endl;
}