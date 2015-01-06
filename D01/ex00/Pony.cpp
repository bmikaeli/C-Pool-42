#include "Pony.hpp"
#include <iostream>

void Pony::speak(void) {
    std::cout << "Hello i'm a Poney, my color is " << this->color << " and my name is " << this->name << std::endl;
}

Pony::Pony(void) {
    std::cout << "entering constructor" << std::endl;

}

Pony::~Pony(void) {
    std::cout << "entering destructor" << std::endl;

}

void Pony::setColor(std::string color) {
    this->color = color;

}

void Pony::setName(std::string name) {
    this->name = name;
}