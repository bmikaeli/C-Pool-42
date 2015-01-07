#ifndef BRAIN_H
# define BRAIN_H

#include <sstream>
#include <iostream>

class Brain {
public:
    Brain(void);

    ~Brain(void);

    std::string identify();

private:
    int IQ;
    int weight;
};

#endif