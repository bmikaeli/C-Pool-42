#ifndef Ninja_TRAP_H
#define Ninja_TRAP_H

#include <iostream>
#include <cstdlib>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class NinjaTrap : public ClapTrap {
public:

    NinjaTrap();

    NinjaTrap(NinjaTrap const &);

    NinjaTrap(std::string const name);

    ~NinjaTrap(void);

    NinjaTrap &operator=(NinjaTrap const &rhs);

    void ninjaShoebox(ScavTrap const &scav);

    void ninjaShoebox(FragTrap const &frag);

    void ninjaShoebox(NinjaTrap const &ninja);

    void ninjaShoebox(ClapTrap const &clap);
};

#endif