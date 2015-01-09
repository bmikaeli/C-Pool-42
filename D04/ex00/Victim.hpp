#ifndef Victim_H
# define Victim_H

#include <iostream>

class Victim {

public:

    Victim(std::string name);

    Victim(const Victim &src);

    virtual ~Victim();

    std::string getName() const;

    Victim &operator=(Victim const &rhs);

    virtual void getPolymorphed() const;

    void setName(std::string name);

protected :

    Victim();

    std::string name;
};

std::ostream &operator<<(std::ostream &o, const Victim &i);

#endif