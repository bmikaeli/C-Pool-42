#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie {
public :
    ~Zombie(void);

    Zombie(void);

    void announce();
    void setName(std::string name);
    void setType(std::string type);
    std::string name;
    std::string type;
};

#endif