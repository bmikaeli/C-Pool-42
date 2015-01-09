#ifndef SUPERMUTANT_H
#define SUPERMUTANT_H

#include "Enemy.hpp"

class SuperMutant : public Enemy {

public:
    SuperMutant();

    ~SuperMutant();

    SuperMutant &operator=(SuperMutant const &rhs);

    void takeDamage(int amount);
};

#endif