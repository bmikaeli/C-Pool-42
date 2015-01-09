#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const &type) {
    this->hp = hp;
    this->type = type;
}

Enemy::~Enemy() {
}

void Enemy::takeDamage(int amount) {
    if (amount > 0) {
        this->hp -= amount;
    }
}

void Enemy::setHP(int amount) {
    this->hp = amount;
}

int Enemy::getHP() const {
    return this->hp;
}

std::string Enemy::getType() const {
    return this->type;
}

Enemy &Enemy::operator=(Enemy const &rhs) {
    this->hp = rhs.getHP();
    this->type = rhs.getType();
    return *this;
}