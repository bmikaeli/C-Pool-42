#ifndef RobotomyRequestForm_H
#define RobotomyRequestForm_H

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class RobotomyRequestForm : public Form {

public:

    RobotomyRequestForm(std::string target);

    ~RobotomyRequestForm(void);

    void execute(const Bureaucrat &executor) const;


private:
    RobotomyRequestForm(void);

};


#endif