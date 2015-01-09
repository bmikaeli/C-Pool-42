#ifndef POWER_FIST_H
#define POWER_FIST_H

#include "AWeapon.hpp"

class PowerFist : public AWeapon {
public:
    PowerFist();

    ~PowerFist();

    PowerFist &operator=(PowerFist const &rhs);

    void attack() const;

private:

};

#endif