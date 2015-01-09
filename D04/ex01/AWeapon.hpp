#ifndef AWEAPON_H
#define AWEAPON_H

#include <iostream>

class AWeapon {
public:
    AWeapon(const std::string &name, int apcost, int damage);

    virtual ~AWeapon();

    std::string getName() const;

    int getAPCost() const;

    int getDamage() const;

    AWeapon &operator=(AWeapon const &rhs);

    virtual void attack() const = 0;

protected:
    std::string name;
    int damage;
    int APcost;

    AWeapon();
};

#endif