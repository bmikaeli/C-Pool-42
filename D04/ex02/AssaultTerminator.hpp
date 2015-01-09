#ifndef ASSAULT_TERMINATOR_H
#define ASSAULT_TERMINATOR_H

#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine {
public :
    AssaultTerminator();

    ~AssaultTerminator();

    ISpaceMarine *clone() const;

    void battleCry() const;

    void rangedAttack() const;

    void meleeAttack() const;
};

#endif