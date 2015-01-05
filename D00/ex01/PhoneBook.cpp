#include "PhoneBook.hpp"
#include <stdlib.h>

void formatOutput(std::string str) {
    int i;
    i = 0;
    while (i < 10) {
        if (str[i] && str[i] != '\0') {
            if (i != 9)
                std::cout << str[i];
            else
                std::cout << ".";
        }
        else
            std::cout << " ";
        i++;
    }
}

void add(Contact *contact) {

    std::string details[10];
    if (contact->getNbContacts() < 8) {
        std::cout << "First Name ? ";
        std::cin >> details[0];
        std::cout << "Last Name ? ";
        std::cin >> details[1];
        std::cout << "Nick Name ? ";
        std::cin >> details[2];
        std::cout << "Login ? ";
        std::cin >> details[3];
        std::cout << "Postal Adresse ? ";
        std::cin >> details[4];
        std::cout << "Email Adress ? ";
        std::cin >> details[5];
        std::cout << "Phone Number ? ";
        std::cin >> details[6];
        std::cout << "Birth Date ? ";
        std::cin >> details[7];
        std::cout << "Favorite Meal ? ";
        std::cin >> details[8];
        std::cout << "UnderWear Color ? ";
        std::cin >> details[9];
        std::cout << "Darkest Secret ? ";
        std::cin >> details[10];
        contact[contact->getNbContacts()].Add(details);
        std::cout << "Contact saved" << std::endl;
    }
    else
        std::cout << "Sorry, 8 entry are already filled. Please, go buy another PhoneBook.";
    std::cout << std::endl;
}

void search(Contact *contacts) {

    int i = 0;
    std::string input;
    int index = -42;

    if (i < contacts[0].getNbContacts()) {
        std::cout << "Index     |FirstName |LastName  |NickName  |" << std::endl;
        while (i < contacts[0].getNbContacts()) {
            contacts[i].displayInfos(i);
            i++;
        }
        std::cout << "Which entry do you want ? ";
        std::cin >> input;
        if (input.length() == 1)
            index = atoi(input.data());
        if (index >= 0 and index < contacts[0].getNbContacts()) {
            contacts[index].displayAllInfos();
        }
        else
            std::cout << "Sorry, this entry does not exists";
        std::cout << std::endl;
    }
    else {
        std::cout << "No entry" << std::endl;
    }
    return;
}
