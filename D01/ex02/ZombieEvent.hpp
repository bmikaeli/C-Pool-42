#ifndef ZOMBIE_EVENT_H
#define ZOMBIE_EVENT_H

#include <iostream>
#include "Zombie.hpp"

class ZombieEvent {

public :
    ZombieEvent(void);
    ~ZombieEvent(void);
    void setZombieType(std::string type, Zombie * zombie);

    Zombie *newZombie(std::string name);

    void randomChump();
};

#endif