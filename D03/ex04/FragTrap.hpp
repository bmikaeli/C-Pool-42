#ifndef FRAG_TRAP_H
#define FRAG_TRAP_H

#include <iostream>
#include <cstdlib>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:

    FragTrap();

    FragTrap(FragTrap const &);

    FragTrap(std::string const name);

    ~FragTrap(void);

    FragTrap &operator=(FragTrap const &rhs);

    void vaulthunter_dot_exe(const std::string &target);
};

#endif