#ifndef Base_Class_H
#define Base_Class_H

class Base {

public:
    Base();

    Base(Base &src);

    virtual ~Base();

    Base &operator=(Base &src);
};

#endif