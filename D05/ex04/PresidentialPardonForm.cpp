#include "PresidentialPardonForm.hpp"
#include <fstream>
#include <string>

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form(target, 25, 5) {
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
    std::cout << "<" << this->getName() << "> has been pardoned by Zafod Beeblebrox." << std::endl;
    (void) executor;
}

PresidentialPardonForm::~PresidentialPardonForm() {

}