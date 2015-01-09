#ifndef SQUAD_H
# define SQUAD_H

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

class Squad : public ISquad {
public:

    Squad(void);

    ~Squad(void);

    int getCount() const;

    ISpaceMarine *getUnit(int);

    int push(ISpaceMarine *);

private:
    ISpaceMarine *container;
    int Count;
};

#endif