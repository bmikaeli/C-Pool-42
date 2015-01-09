#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character {
public:

    Character(const std::string &name);

    ~Character();

    void recoverAP();

    void equip(AWeapon *);

    int getAP(void) const;

    Character &operator=(Character const &rhs);


    void attack(Enemy *);

    AWeapon *getWeapon() const;

    std::string getName() const;

private:
    std::string name;
    int AP;
    AWeapon *weapon;
};

std::ostream &operator<<(std::ostream &o, const Character &i);

#endif