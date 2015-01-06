#ifndef HUMAN_A_H
# define HUMAN_A_H

#include <iostream>
#include "Weapon.hpp"

class HumanA {
public:
    void attack();

    HumanA(std::string name, Weapon &weapon);

    ~HumanA(void);

private:
    std::string name;
    Weapon &weapon;
};

#endif