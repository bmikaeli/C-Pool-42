#include "Form.hpp"

Form::Form(std::string name, short gradeSign, short gradeExecute)
        : name(name), gradeSign(gradeSign), gradeExecute(gradeExecute) {
    this->validated = false;
    try {
        if (gradeSign < 0 || gradeExecute < 0) {
            throw GradeTooHighException();
        }
        else if (gradeSign > 150 || gradeExecute > 150) {

            throw GradeTooLowException();
        }
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}


Form &Form::operator=(Form &src) {
    this->validated = src.getValidated();
    return *this;
}

Form::~Form() {
}

bool Form::getValidated() const {
    return this->validated;
}

std::string Form::getName() const {
    return this->name;
}

short Form::getGradeExecute() const {
    return this->gradeExecute;
}

short Form::getGradeSign() const {
    return this->gradeSign;
}

void Form::beSigned(Bureaucrat &src) {
    if (src.getGrade() <= this->gradeSign) {
        this->validated = true;
    }
    else {
        throw GradeTooLowException();
    }
}

std::ostream &operator<<(std::ostream &o, Form &rhs) {
    o << "<" << rhs.getName() << ">" << ", Form SignGrade <" << rhs.getGradeSign() << "> and ExecuteGrade <" << rhs.getGradeExecute() << ">";
    if (rhs.getValidated() == true) {
        o << " is signed";
    }
    else
        o << " is not signed";
    o << std::endl;
    return o;
}