#ifndef C_H
#define C_H

#include "baseClass.hpp"

class C : public Base {

public:
    virtual ~C();

    C();

    C(C &src);

    C &operator=(C &src);
};

#endif