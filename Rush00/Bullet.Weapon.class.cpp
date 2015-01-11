#include "Bullet.Weapon.class.hpp"

Bullet::Bullet(int x, int y, int direction, char * skin) : X(x), Y(y), direction(direction){
	this->skin = skin;
}

Bullet &Bullet::operator=(const Bullet &rhs) {
    this->Y = rhs.Y;
    this->X = rhs.X;
    this->direction = rhs.direction;
    this->skin = rhs.skin;
    return *this;
}

Bullet::~Bullet() {

}

Bullet::Bullet() {
}
