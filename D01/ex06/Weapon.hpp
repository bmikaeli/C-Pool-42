#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>

class Weapon {
public:
    Weapon(std::string type);

    ~Weapon(void);

    void setType(std::string);

    const std::string &getType(void);

private:
    std::string type;
};

#endif