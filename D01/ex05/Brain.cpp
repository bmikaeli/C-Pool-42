#include "Brain.hpp"

Brain::Brain(void) {
    std::cout << "Brain Constructor called" << std::endl;
}

Brain::~Brain(void) {
    std::cout << "Brain Destructor called" << std::endl;
}

std::string Brain::identify() {

    std::string str;
    std::ostringstream  convert;
    convert << this;
    str =  convert.str();
    return str;
}