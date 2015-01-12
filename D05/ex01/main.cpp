#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    Bureaucrat b("joe", 40);

    Bureaucrat b1("Tom", 60);
    Form f("formtest", 50, 100);
    Form f1("formtest1", 50, 100);

    std::cout << b << b1 << f << std::endl << std::endl;

    std::cout << f << std::endl;
    std::cout << "first try : " << std::endl;
    try {
        f.beSigned(b1);
    }
    catch (std::exception const &e) {
        std::cout << b1 << e.what() << std::endl;
    }
    std::cout << f << std::endl;


    std::cout << "second try : " << std::endl;
    try {
        f.beSigned(b);
    }
    catch (std::exception const &e) {
        std::cout << b << e.what() << std::endl << std::endl;
    }

    std::cout << f << std::endl;
    b.signForm(f);
    b.signForm(f1);

    return 0;
}