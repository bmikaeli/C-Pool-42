#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

#include <iostream>
#include <cmath>

class Fixed {

public :
    Fixed(void);

    Fixed(int const raw);

    Fixed(float const raw);

    Fixed(Fixed const &src);

    ~Fixed(void);

    Fixed &operator=(Fixed const &rhs);

    float toFloat(void) const;

    int toInt(void) const;

    void setRawBits(int const raw);

    int getRawBits(void) const;

private:
    const int fractionalbBits;
    int rawBits;

};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif