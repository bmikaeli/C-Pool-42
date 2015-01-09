#ifndef Peon_H
# define Peon_H

#include <iostream>
#include "Victim.hpp"

class Peon : public Victim {

public:

    Peon(std::string name);

    Peon(const Peon &src);

    Peon &operator=(Peon const &rhs);

    ~Peon();

    void getPolymorphed() const;

private :

    Peon();
};

#endif