#include "OfficeBlock.hpp"
#include <fstream>
#include <string>

OfficeBlock::OfficeBlock() {

}

OfficeBlock::OfficeBlock(Intern *i, Bureaucrat *sign, Bureaucrat *executive) {
    this->intern = i;
    this->sign = sign;
    this->executive = executive;
}

OfficeBlock::~OfficeBlock() {
}

void OfficeBlock::setExecutor(Bureaucrat &src) {
    this->executive = &src;
}

void OfficeBlock::setIntern(Intern &src) {
    this->intern = &src;
}

void OfficeBlock::setSigner(Bureaucrat &src) {
    this->sign = &src;
}

void OfficeBlock::doBureaucracy(std::string name, std::string target) {
    Form *form;
    form = this->intern->makeForm(name, target);
    this->sign->signForm(*form);
    this->executive->executeForm(*form);
}