#include "Human.hpp"
#include "Brain.hpp"

int main() {

    Human bob;
    std::cout << bob.identify() << std::endl;
    std::cout << bob.getBrain().identify() << std::endl;
}