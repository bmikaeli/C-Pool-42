#ifndef  ROCKETLAUNCHER_H
#define ROCKETLAUNCHER_H

#include "Aweapon.class.hpp"
#include "WindowRetro.class.hpp"

class RocketLauncher : public Aweapon {
public :
    RocketLauncher();

    RocketLauncher(RocketLauncher &src);

    RocketLauncher &operator=(RocketLauncher const &rhs);

    ~RocketLauncher();
};

#endif