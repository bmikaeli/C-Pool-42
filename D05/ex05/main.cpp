#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int main() {

    Intern idiotOne;
    Bureaucrat hermes("Hermes Conrad", 37);
    Bureaucrat bob("Bobby Bobson", 123);
    OfficeBlock ob;
    ob.setIntern(idiotOne);
    ob.setSigner(bob);
    ob.setExecutor(hermes);
    try {
        ob.doBureaucracy("shrubbery creation", "Pigley");
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}