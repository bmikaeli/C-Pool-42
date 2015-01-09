#ifndef TACTICAL_MARINE_H
#define TACTICAL_MARINE_H

#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine {
public :
    TacticalMarine();

    ~TacticalMarine();

    ISpaceMarine *clone() const;

    void battleCry() const;

    void rangedAttack() const;

    void meleeAttack() const;
};

#endif