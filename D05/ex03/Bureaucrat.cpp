#include "Bureaucrat.hpp"
#include "Form.hpp"


Bureaucrat::Bureaucrat(std::string name, short grade) : name(name) {
    if (grade < 0) {
        throw GradeTooHighException();
    }
    else if (grade > 150) {
        throw GradeTooLowException();
    }
    else
        this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat &src) : name(src.getName()) {
    this->grade = src.getGrade();
}

void Bureaucrat::decrementGrade() {
    if (this->grade + 1 > 150) {
        throw GradeTooLowException();
    }
    else {
        this->grade++;
    }
}

void Bureaucrat::incrementGrade() {
    if (this->grade - 1 <= 0) {
        throw GradeTooHighException();
    }
    else {
        this->grade--;
    }
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &src) {
    this->grade = src.getGrade();
    return *this;
}

short Bureaucrat::getGrade() const {
    return this->grade;
}

std::string Bureaucrat::getName() {
    return this->name;
}

void Bureaucrat::signForm(Form &src) {

    src.beSigned(*this);
    if (src.getGradeSign() >= this->getGrade()) {
        std::cout << "<" << this->name << "> signs " << src.getName() << std::endl;
    }
    else {
        std::cout << "<" << this->name << "> cannot signs " << src.getName() << " because " << "the form grade is too low" << std::endl;
    }
}

Bureaucrat::~Bureaucrat() {

}

std::ostream &operator<<(std::ostream &o, Bureaucrat &rhs) {
    o << "<" << rhs.getName() << ">" << ", bureaucrat grade <" << rhs.getGrade() << ">" << std::endl;
    return o;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too High";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too Low";
}

void Bureaucrat::executeForm(Form const &form) {
    try {
        form.execute(*this);
        std::cout << "<bureaucrat> executes <" << form.getName() << ">" << std::endl;

    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}