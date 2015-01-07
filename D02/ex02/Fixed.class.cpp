#include "Fixed.class.hpp"
#include <iostream>

Fixed::Fixed(void) : fractionalbBits(8) {
    this->setRawBits(0);
    std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(int const raw) : fractionalbBits(8) {
    this->rawBits = raw << 16;
    std::cout << "Int Constructor called" << std::endl;
}

Fixed::Fixed(float const raw) : fractionalbBits(8) {
    this->setRawBits(raw * 65536);
    std::cout << "Float Constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) : fractionalbBits(8), rawBits(0) {
    std::cout << "Copy Constructor called" << std::endl;
    *this = src;
    return;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}


void Fixed::setRawBits(int const raw) {
    this->rawBits = raw;
}

int Fixed::getRawBits(void) const {
    return this->rawBits;
}

float Fixed::toFloat(void) const {
    return (float) (this->rawBits) / 65536;
}

int Fixed::toInt(void) const {
    return (this->rawBits + 32768) >> 16;
}

Fixed &Fixed::operator=(Fixed const &rhs) {
    std::cout << "Assignation operator called" << std::endl;
    this->rawBits = rhs.getRawBits();
    return *this;
}

Fixed &Fixed::operator+(Fixed const &rhs) {
    std::cout << "Addition operator called" << std::endl;
    return Fixed(this->rawBits + rhs.getRawBits());
}

Fixed &Fixed::operator-(Fixed const &rhs) {
    std::cout << "Addition operator called" << std::endl;
    return Fixed(this->rawBits - rhs.getRawBits());
}

Fixed &Fixed::operator/(Fixed const &rhs) {
    std::cout << "Addition operator called" << std::endl;
    return Fixed(this->rawBits / rhs.getRawBits());
}

Fixed &Fixed::operator*(Fixed const &rhs) {
    std::cout << "Addition operator called" << std::endl;
    return Fixed(this->rawBits * rhs.getRawBits());
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs) {
    o << rhs.toFloat();
    return o;
}