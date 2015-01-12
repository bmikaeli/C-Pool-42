#ifndef Intern_H
#define Intern_H

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

class Intern {

public:

    class NoForm : public std::exception {
        virtual const char *what() const throw();
    };

    Intern(void);

    Intern(Intern &src);

    ~Intern(void);

    Form *makeForm(std::string name, std::string target);

    Intern &operator=(Intern &src);

private:

};

std::ostream &operator<<(std::ostream &o, Intern &rhs);

#endif