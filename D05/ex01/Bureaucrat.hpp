#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include "Form.hpp"
#include <iostream>

class Bureaucrat {

public:

    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return "Grade too High";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return "Grade too low";
        }
    };

    Bureaucrat(std::string name, short grade);

    Bureaucrat(Bureaucrat &src);

    ~Bureaucrat(void);

    void incrementGrade();

    void decrementGrade();

    void signForm(Form &src);

    std::string getName(void);

    Bureaucrat &operator=(Bureaucrat &src);

    short getGrade(void);

private:

    const std::string name;
    short grade;

    Bureaucrat(void);

};

std::ostream &operator<<(std::ostream &o, Bureaucrat &rhs);

#else
class Bureaucrat;
#endif