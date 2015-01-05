#include <iostream>
#include "Contact.Class.hpp"
#include "PhoneBook.hpp"

int main() {
    std::string input;
    Contact contacts[8];
    while (1) {
        input = " ";
        std::cout << "Input ? ";
        std::cin >> input;
        if (input == "EXIT") {
            break;
        }
        else if (input == "SEARCH") {
            search(contacts);
        }
        else if (input == "ADD") {
            add(contacts);
            continue;
        }
        else
            continue;
    }

    return 0;
}

