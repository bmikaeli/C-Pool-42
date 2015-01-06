#include <iostream>

int main() {
    std::string simplestring = "HI THIS IS BRAIN";
    std::string *pointer = &simplestring;
    std::string &ref = simplestring;

    std::cout << "pointeur : " << *pointer << std::endl;
    std::cout << "Ref : " << ref << std::endl;

    return 0;
}