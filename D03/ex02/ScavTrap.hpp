#ifndef SCAV_TRAP_H
#define SCAV_TRAP_H
#include <iostream>
#include <cstdlib>
#include "ClapTrap.hpp"
class ScavTrap : public ClapTrap
{
public:

    ScavTrap();

    ScavTrap(ScavTrap const &);

    ScavTrap(std::string const name);

    ~ScavTrap(void);

    ScavTrap &operator=(ScavTrap const &rhs);

    void challengeNewcomer(std::string const &target) const;
};
#endif