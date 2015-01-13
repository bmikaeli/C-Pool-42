#ifndef B_H
#define B_H

#include "baseClass.hpp"

class B : public Base {

public:
    virtual ~B();

    B();

    B(B &src);

    B &operator=(B &src);
};

#endif