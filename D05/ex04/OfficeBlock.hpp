#ifndef OfficeBlock_H
#define OfficeBlock_H

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"

class OfficeBlock {

public:

    OfficeBlock();

    OfficeBlock(Intern *i, Bureaucrat *sign, Bureaucrat *executive);

    ~OfficeBlock(void);

    void setIntern(Intern &src);

    void setSigner(Bureaucrat &src);

    void setExecutor(Bureaucrat &src);

    void doBureaucracy(std::string name, std::string target);

private:
    Intern *intern;
    Bureaucrat *sign;
    Bureaucrat *executive;

};


#endif