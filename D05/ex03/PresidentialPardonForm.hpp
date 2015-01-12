#ifndef PresidentialPardonForm_H
#define PresidentialPardonForm_H

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class PresidentialPardonForm : public Form {

public:

    PresidentialPardonForm(std::string target);

    ~PresidentialPardonForm(void);

    void execute(const Bureaucrat &executor) const;


private:
    PresidentialPardonForm(void);

};

#endif