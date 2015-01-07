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

    Fixed &operator=(Fixed const &rhs);

    Fixed &operator++();

    Fixed operator++(int);

    Fixed operator*(Fixed const &rhs) const;

    Fixed operator-(Fixed const &rhs) const;

    Fixed operator/(Fixed const &rhs) const;

    Fixed operator+(Fixed const &rhs) const;

    Fixed operator>(Fixed const &rhs) const;

    Fixed operator<(Fixed const &rhs) const;

    Fixed operator>=(Fixed const &rhs) const;

    Fixed operator<=(Fixed const &rhs) const;

    Fixed operator==(Fixed const &rhs) const;

    Fixed operator!=(Fixed const &rhs) const;

    float toFloat(void) const;

    int toInt(void) const;

    void setRawBits(int const raw);

    int getRawBits(void) const;

    ~Fixed(void);

private:
    const int fractionalbBits;
    int rawBits;

};

std::ostream &operator<<(std::ostream &o, Fixed const &i);
Fixed max(Fixed const &a, Fixed const &b);
Fixed min(Fixed const &a, Fixed const &b);

#endif