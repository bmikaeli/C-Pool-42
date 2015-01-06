#ifndef ZOMBIE_HORDE_H
# define ZOMBIE_HORDE_H

#include "Zombie.hpp"
#include <cstdlib>
#include <iostream>

class ZombieHorde {
public:
    ZombieHorde(int N);

    ~ZombieHorde(void);

    void announce();

    Zombie *horde;

private:
    void createZombie(int N);
    int numberOfZombie;
};

#endif