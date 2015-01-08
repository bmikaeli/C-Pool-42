#ifndef Super_TRAP_H
#define Super_TRAP_H

#include <iostream>
#include <cstdlib>
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public virtual FragTrap, public virtual NinjaTrap {
public:

    SuperTrap();

    SuperTrap(SuperTrap const &);

    SuperTrap(std::string const name);

    ~SuperTrap(void);

    SuperTrap &operator=(SuperTrap const &rhs);

};

#endif