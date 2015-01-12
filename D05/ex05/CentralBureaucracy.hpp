#ifndef CentralBureaucracy_H
#define CentralBureaucracy_H

#include <iostream>
#include "Bureaucrat.hpp"
#include "OfficeBlock.hpp"
#include "Form.hpp"

class CentralBureaucracy : public Form {

public:


    CentralBureaucracy(void);

    ~CentralBureaucracy(void);


    void execute(const Bureaucrat &executor) const;

private:
    OfficeBlock *allOfices;

};


#endif