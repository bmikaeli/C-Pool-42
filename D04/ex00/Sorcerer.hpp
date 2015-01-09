#ifndef SORCERER_H
# define SORCERER_H

#include <iostream>
#include "Victim.hpp"

class Sorcerer {

public:

    Sorcerer(std::string name, std::string title);

    Sorcerer(const Sorcerer &src);

    void polymorph(Victim const &src);

    std::string getName() const;

    void setName(std::string);

    Sorcerer &operator=(Sorcerer const &rhs);

    std::string getTitle() const;

    void setTitle(std::string);

    ~Sorcerer();

private :
    Sorcerer();

    std::string name;
    std::string title;
};

std::ostream &operator<<(std::ostream &o, const Sorcerer &i);

#endif