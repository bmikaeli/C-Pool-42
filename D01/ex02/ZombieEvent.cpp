#include "ZombieEvent.hpp"
#include "Zombie.hpp"
#include <cstdlib>

void ZombieEvent::setZombieType(std::string type, Zombie *zombie) {
    zombie->setType(type);
}

Zombie *ZombieEvent::newZombie(std::string name) {
    Zombie *tmpZombie = new Zombie();
    tmpZombie->name = name;
    return tmpZombie;
}

void ZombieEvent::randomChump() {
    Zombie *randomZombie;
    randomZombie = new Zombie();
    int random;
    std::string arrayRand[3];
    std::srand(time(NULL));
    random = std::rand() % 3;

    arrayRand[0] = "John";
    arrayRand[1] = "Frank";
    arrayRand[2] = "Anthony";

    randomZombie->setName(arrayRand[random]);
    this->setZombieType("typeRandom", randomZombie);
    randomZombie->announce();
    delete randomZombie;
}

ZombieEvent::ZombieEvent() {
    std::cout << "event constructor called" << std::endl;


}

ZombieEvent::~ZombieEvent() {
    std::cout << "event destuctor called" << std::endl;

}