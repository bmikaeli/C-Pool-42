#include <iostream>
#include "Contact.Class.hpp"
#include "PhoneBook.hpp"


Contact::Contact(void) {
    return;
}

Contact::~Contact(void) {
    return;
}


void Contact::displayAllInfos() {

    std::cout << std::endl;
    std::cout << this->firstName;
    std::cout << std::endl;
    std::cout << this->lastName;
    std::cout << std::endl;
    std::cout << this->nickName;
    std::cout << std::endl;
    std::cout << this->login;
    std::cout << std::endl;
    std::cout << this->postalAdress;
    std::cout << std::endl;
    std::cout << this->email;
    std::cout << std::endl;
    std::cout << this->phoneNumber;
    std::cout << std::endl;
    std::cout << this->birthDate;
    std::cout << std::endl;
    std::cout << this->favoriteMeal;
    std::cout << std::endl;
    std::cout << this->underwearColor;
    std::cout << std::endl;
    std::cout << this->darkestSecret;
}

void Contact::displayInfos(int i) {

    std::cout << i << "         |";
    formatOutput(this->firstName);
    std::cout << "|";
    formatOutput(this->lastName);
    std::cout << "|";
    formatOutput(this->nickName);
    std::cout << "|";
    std::cout << std::endl;
}

void Contact::Add(std::string *details) {
    this->firstName = details[0];
    this->lastName = details[1];
    this->nickName = details[2];
    this->login = details[3];
    this->postalAdress = details[4];
    this->email = details[5];
    this->phoneNumber = details[6];
    this->birthDate = details[7];
    this->favoriteMeal = details[8];
    this->underwearColor = details[9];
    this->darkestSecret = details[10];
    Contact::nbContacts += 1;
    return;
}

int Contact::getNbContacts(void) {
    return Contact::nbContacts;
}

int Contact::nbContacts = 0;
