#include "Bullet.Weapon.class.hpp"

Bullet::Bullet(int x, int y, int direction) : X(x), Y(y), direction(direction) {
//    std::cout << "Bullet created" << std::endl;
}

Bullet &Bullet::operator=(const Bullet &rhs) {
    this->Y = rhs.Y;
    this->X = rhs.X;
    this->direction = rhs.direction;
    return *this;
}

Bullet::~Bullet() {

    std::cout << "Bullet destructed" << std::endl;


}

Bullet::Bullet() {
//    std::cout << "Bullet created" << std::endl;
}