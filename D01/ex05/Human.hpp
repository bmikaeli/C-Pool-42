#ifndef HUMAN_H
# define HUMAN_H

#include <iostream>
#include "Brain.hpp"

class Human {
public:
    Human(void);

    ~Human(void);

    Brain &getBrain();

    std::string identify(void);

private:
    const Brain brain;

};

#endif