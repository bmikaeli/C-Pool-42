#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

#include <iostream>

class Fixed {

public :
    Fixed(void);

    Fixed(int const raw);

    Fixed(Fixed const &src);

    ~Fixed(void);

    Fixed &operator=(Fixed const &rhs);

    void setRawBits(int const raw);

    int getRawBits(void) const;

private:
    const int fractionalbBits;
    int rawBits;

};

#endif