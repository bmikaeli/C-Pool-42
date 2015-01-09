#ifndef PLASMA_RIFLE_H
#define PLASMA_RIFLE_H

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {
public:
    PlasmaRifle();

    ~PlasmaRifle();

    PlasmaRifle &operator=(PlasmaRifle const &rhs);

    void attack() const;

private:

};

#endif