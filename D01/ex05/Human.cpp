#include "Human.hpp"
#include "Brain.hpp"

Human::Human(void) : brain(*(new Brain)) {
    std::cout << "Human Constructor called" << std::endl;
}

Human::~Human(void) {

    std::cout << "Human Destructor called" << std::endl;
}

std::string Human::identify() {
    return this->getBrain().identify();

}
Brain &Human::getBrain() {
    return (Brain &) this->brain;
}
