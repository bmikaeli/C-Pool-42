#include "Human.hpp"

Human::Human(void) {
    std::cout << "Human Constructor called" << std::endl;
    Brain *brain = new Brain();
    this->brain = brain;
}

Human::~Human(void) {

    std::cout << "Human Destructor called" << std::endl;
    delete this->brain;
}

std::string Human::identify() {

    return this->brain->identify();

}
Brain * Human::getBrain()
{
    return this->brain;
}
