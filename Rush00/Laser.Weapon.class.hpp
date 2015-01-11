#ifndef  LASER_H
#define LASER_H

#include "Aweapon.class.hpp"

class Laser : public Aweapon {
public :
    Laser(Laser &src);

    Laser();

    Laser &operator=(Laser const &rhs);

    ~Laser();
};

#endif