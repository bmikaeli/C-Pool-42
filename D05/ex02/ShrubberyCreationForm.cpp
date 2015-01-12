#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form(target, 145, 137){

}


//ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &src) {
//    this->validated = src.getValidated();
//    return *this;
//}
//ShrubberyCreationForm::~ShrubberyCreationForm() {
//}
//
//void ShrubberyCreationForm::beSigned(Bureaucrat &src) {
//    if (src.getGrade() <= this->gradeSign) {
//        this->validated = true;
//    }
//    else {
//        throw GradeTooLowException();
//    }
//}
//
//std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm &rhs) {
//    o << "<" << rhs.getName() << ">" << ", ShrubberyCreationForm SignGrade <" << rhs.getGradeSign() << "> and ExecuteGrade <" << rhs.getGradeExecute() << ">";
//    if (rhs.getValidated() == true) {
//        o << " is signed";
//    }
//    else
//        o << " is not signed";
//    o << std::endl;
//    return o;
//}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}