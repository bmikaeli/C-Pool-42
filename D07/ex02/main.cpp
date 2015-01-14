#include "Array.hpp"
#include <iostream>

int main() {
    Array<int> a = Array<int>(3);

    Array<int> b = Array<int>(3);
    b = a;

    try {
        std::cout << "assignation de a[0]" << std::endl;
        a[0] = 1;

        std::cout << "assignation de a[1]" << std::endl;
        a[1] = 2;

        std::cout << "assignation de a[2]" << std::endl;
        a[2] = 3;

        std::cout << "assignation de a[3]" << std::endl;
        a[3] = 4;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << "a[0] : " << a[0] << std::endl;
        std::cout << "a[1] : " << a[1] << std::endl;
        std::cout << "a[2] : " << a[2] << std::endl;
        std::cout << "a[3] : " << a[3] << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}