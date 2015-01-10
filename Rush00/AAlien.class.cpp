#include "AAlien.class.hpp"

void AAlien::takeDamage(int amount) {
    this->hp -= amount;
}

AAlien::AAlien() {
}

AAlien::~AAlien() {
}

void AAlien::draw(WINDOW *plate, int Y, int x) const {


}