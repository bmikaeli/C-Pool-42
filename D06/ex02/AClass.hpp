#ifndef A_H
#define A_H

#include "baseClass.hpp"

class A : public Base {

public:
    A();

    A(A &src);

    virtual ~A();

    A &operator=(A &src);
};

#endif