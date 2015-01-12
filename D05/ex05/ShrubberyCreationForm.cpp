#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form(target, 145, 137) {

}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {

    if (this->getValidated() == true && this->getGradeExecute() >= executor.getGrade()) {
        std::string filename;

        filename = this->getName();
        filename += "_shrubbery";
        std::ofstream fh(filename.data(), std::ios::out);

        if (fh) {
            fh << " .oo689ou. " << std::endl;
            fh << "98O9PS9689P" << std::endl;
            fh << "S9968D8O886" << std::endl;
            fh << " 9O89S9889 " << std::endl;
            fh << "  ``|&|''  " << std::endl;
            fh << "    |%|    " << std::endl;
            fh << "    |%|    " << std::endl;
            fh << "   .:%:.   " << std::endl;
            fh.close();
        }
        else
            std::cerr << "Can't open the file!" << std::endl;
    }
    else
        throw Form::GradeTooLowException();

}


ShrubberyCreationForm::~ShrubberyCreationForm() {
}
