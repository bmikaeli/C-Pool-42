#ifndef I_SPACE_MARINE_H
#define I_SPACE_MARINE_H

#include <iostream>
class ISpaceMarine {
public:
    virtual ~ISpaceMarine() {}

    virtual const ISpaceMarine *clone() const = 0;

    virtual void battleCry() const = 0;

    virtual void rangedAttack() const = 0;

    virtual void meleeAttack() const = 0;
};

#endif