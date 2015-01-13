#include <iostream>
#include <cstdlib>
#include "AClass.hpp"
#include "BClass.hpp"
#include "CClass.hpp"
#include "baseClass.hpp"


Base *generate(void) {
    std::srand(time(NULL));
    Base *ret;

    int random = rand() % 3;
    if (random == 0) {
        ret = new C();

    }
    else if (random == 1) {
        ret = new A();

    }
    else {
        ret = new B();
    }
    return ret;
}

void identify_from_pointer(Base *p) {
    A *testA = dynamic_cast<A *>(p);
    if (testA != NULL) {
        std::cout << "A" << std::endl;
    }
    C *testC = dynamic_cast<C *>(p);
    if (testC != NULL) {
        std::cout << "C" << std::endl;
    }
    B *testB = dynamic_cast<B *>(p);
    if (testB != NULL) {
        std::cout << "B" << std::endl;
    }
}

void identify_from_reference(Base &p) {
    try {
        dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
    }
    catch (std::exception &e) {
    }
    try {
        dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
    }
    catch (std::exception &e) {
    }
    try {
        dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
    }
    catch (std::exception &e) {
    }
}

int main() {
    Base *instance = generate();
    identify_from_pointer(instance);
    identify_from_reference(*instance);

    return 0;
}