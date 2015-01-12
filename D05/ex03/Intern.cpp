#include "Intern.hpp"


Intern::Intern() {

}

Intern::Intern(Intern &src) {
    (void) src;
}

Intern::~Intern() {

}

Form *Intern::makeForm(std::string name, std::string target) {
    if (name == "robotomy request") {
        Form *ret = new RobotomyRequestForm(target);
        std::cout << "Intern creates <" << name << ">" << std::endl;
        return ret;

    }
    else if (name == "presidential pardon") {
        Form *ret = new PresidentialPardonForm(target);

        std::cout << "Intern creates <" << name << ">" << std::endl;
        return ret;

    }
    else if (name == "shrubbery creation") {
        Form *ret = new ShrubberyCreationForm(target);
        std::cout << "Intern creates <" << name << ">" << std::endl;
        return ret;

    }
    else {
        throw NoForm();
    }
}

const char *Intern::NoForm::what() const throw() {
    return "Intern cannot creates the form 'coz it's not matching any Forms\n";
}