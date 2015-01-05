#ifndef PhoneBook_H
# define PhoneBook_H

#include <iostream>
#include "Contact.Class.hpp"

void formatOutput(std::string str);

void search(Contact *contacts);

void add(Contact *contact);

#endif