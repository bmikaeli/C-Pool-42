#include "Fixed.class.hpp"

Fixed::Fixed(void) : fractionalbBits(8) {
    this->setRawBits(0);
    std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(int const raw) : fractionalbBits(raw) {
    this->setRawBits(0);
    std::cout << "Parametric Constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) : fractionalbBits(8) {
    std::cout << "Copy Constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &rhs) {
    std::cout << "Assignation operator called" << std::endl;
    this->rawBits = rhs.getRawBits();
    return *this;
}

void Fixed::setRawBits(int const raw) {
    this->rawBits = raw;
}

int Fixed::getRawBits(void) const {

    std::cout << "getRawBits member function called" << std::endl;
    return this->rawBits;
}
