#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>

class Enemy {
protected:
    int hp;
    std::string type;

public:
    Enemy(int hp, std::string const &type);

    virtual ~Enemy();

    std::string getType() const;

    int getHP() const;

    void setHP(int amount);

    Enemy &operator=(Enemy const &rhs);

    virtual void takeDamage(int amount);
};

#endif