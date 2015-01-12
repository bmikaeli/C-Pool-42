#ifndef ShrubberyCreationForm_H
#define ShrubberyCreationForm_H

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class ShrubberyCreationForm : public Form {

public:

    ShrubberyCreationForm(std::string target);

    ~ShrubberyCreationForm(void);

    void execute(const Bureaucrat &executor) const;


private:
    ShrubberyCreationForm(void);

};


#endif