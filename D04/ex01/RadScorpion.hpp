#ifndef RAD_SCORPION_H
#define RAD_SCORPION_H

#include "Enemy.hpp"

class RadScorpion : public Enemy {

public:
    RadScorpion();

    ~RadScorpion();

    RadScorpion &operator=(RadScorpion const &rhs);

    void takeDamage(int amount);
};

#endif