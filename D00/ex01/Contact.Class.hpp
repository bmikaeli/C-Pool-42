#ifndef Contact_Class_H
# define Contact_Class_H

#include <iostream>


class Contact {
public:
    Contact(void);

    ~Contact(void);

    void Add(std::string *detail);

    void Search(void);

    void Delete(void);

    void displayInfos(int i);

    void displayAllInfos(void);

    static int getNbContacts(void);

private:

    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string login;
    std::string postalAdress;
    std::string email;
    std::string phoneNumber;
    std::string birthDate;
    std::string favoriteMeal;
    std::string underwearColor;
    std::string darkestSecret;
    static int nbContacts;
};

#endif