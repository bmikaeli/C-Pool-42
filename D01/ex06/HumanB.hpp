#ifndef HUMAN_B_H
# define HUMAN_B_H

#include <iostream>
#include "Weapon.hpp"

class HumanB {
public:

    HumanB(std::string name);

    void attack();

    void setWeapon(Weapon &weapon);

    ~HumanB(void);

private:
    std::string name;
    Weapon *weapon;
};

#endif