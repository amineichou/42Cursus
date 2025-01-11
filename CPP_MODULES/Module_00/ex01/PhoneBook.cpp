/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:40:46 by moichou           #+#    #+#             */
/*   Updated: 2024/11/21 12:44:07 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    ContactsCount = 0;
    for (int i = 0; i < 8; i++)
    {
        Contacts[i].setFirstName("");
    }
}

PhoneBook::~PhoneBook() {}

int isEmptyString(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isspace(str[i]))
            return 0;
    }
    return 1;
}

int isStrNumber(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] > '9' || str[i] < '0')
            return 0;
    }
    return 1;
}

int isPrintable(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isalnum(str[i]) && str[i] != ' ')
            return 0;
    }
    return 1;
}

void PhoneBook::addContact()
{
    Contact NewContact;
    std::string detail;

    std::cout << "First name : ";
    if (!std::getline(std::cin, detail) || !detail.length() || isEmptyString(detail) || !isPrintable(detail))
    {
        std::cout << "Error adding contact first name is not valid!" << std::endl;
        return;
    }
    else
    {
        NewContact.setFirstName(detail);
    }

    std::cout << "Last name : ";
    if (!std::getline(std::cin, detail) || !detail.length() || isEmptyString(detail) || !isPrintable(detail))
    {
        std::cout << "Error adding contact last name is not valid!" << std::endl;
        return;
    }
    else
    {
        NewContact.setLastName(detail);
    }

    std::cout << "Nick name : ";
    if (!std::getline(std::cin, detail) || !detail.length() || detail.empty() || !isPrintable(detail))
    {
        std::cout << "Error adding contact : nick name is not valid!" << std::endl;
        return;
    }
    else
    {
        NewContact.setNickName(detail);
    }

    std::cout << "Phone number : ";
    if (!std::getline(std::cin, detail) || !detail.length() || isEmptyString(detail) || !isStrNumber(detail) || !isPrintable(detail))
    {
        std::cout << "Error adding contact : phone number is not valid!" << std::endl;
        return;
    }
    else
    {
        NewContact.setPhoneNumber(detail);
    }

    std::cout << "Darkest secret : ";
    if (!std::getline(std::cin, detail) || !detail.length() || isEmptyString(detail) || !isPrintable(detail))
    {
        std::cout << "Error adding contact : Darkest secret is not valid!" << std::endl;
        return;
    }
    else
    {
        NewContact.setDarkestSecret(detail);
    }

    if (ContactsCount >= 8)
    {
        ContactsCount = 0;
        NewContact.setIndex(ContactsCount);
        Contacts[ContactsCount] = NewContact;
        std::cout << "Contact added successfully ✅" << std::endl;
        return;
    }
    NewContact.setIndex(ContactsCount);
    Contacts[ContactsCount] = NewContact;
    ContactsCount++;
    std::cout << "Contact added successfully ✅" << std::endl;
}

long long strToNum(std::string cmd)
{
    if (cmd.length() < 1 || !isStrNumber(cmd))
        return (-1);
    return (std::strtoll(cmd.c_str(), NULL, 10));
}

void PhoneBook::searchContacts()
{
    if (!Contacts[0].getFirstName().length())
    {
        std::cout << "No contacts in the phone book!\n";
        return;
    }

    std::cout << "+-------------------------------------------+" << std::endl;
    std::cout << "|";
    std::cout << std::setw(10) << std::right << "index";
    std::cout << "|";
    std::cout << std::setw(10) << std::right << "first name";
    std::cout << "|";
    std::cout << std::setw(10) << std::right << "last name";
    std::cout << "|";
    std::cout << std::setw(10) << std::right << "nickname";
    std::cout << "|" << std::endl;
    std::cout << "+-------------------------------------------+" << std::endl;

    for (int i = 0; i < 8; i++)
    {
        if (Contacts[i].getFirstName().length())
        {
            std::string firstName = Contacts[i].getFirstName().length() > 10 ? Contacts[i].getFirstName().substr(0, 9) + "." : Contacts[i].getFirstName();
            std::string lastName = Contacts[i].getLastName().length() > 10 ? Contacts[i].getLastName().substr(0, 9) + "." : Contacts[i].getLastName();
            std::string nickName = Contacts[i].getNickName().length() > 10 ? Contacts[i].getNickName().substr(0, 9) + "." : Contacts[i].getNickName();
            std::cout << "|" << std::setw(10) << std::right << i
                      << "|" << std::setw(10) << std::right << firstName
                      << "|" << std::setw(10) << std::right << lastName
                      << "|" << std::setw(10) << std::right << nickName << "|" << std::endl;
            std::cout << "+-------------------------------------------+" << std::endl;
        }
    }

    std::string cmd;
    std::cout << "enter a contact id to see details : ";
    if (!std::getline(std::cin, cmd) )
    {
        std::cout << "error reading command" << std::endl;
        exit(1);
    }

    long long id = strToNum(cmd);
    if (id == -1 || id >= 8)
    {
        std::cout << "Index is not available" << std::endl;
        return;
    }
    else
    {
        if (Contacts[id].getFirstName().length())
        {
            std::cout << "first name : " << Contacts[id].getFirstName() << std::endl;
            std::cout << "last name : " << Contacts[id].getLastName() << std::endl;
            std::cout << "nick name : " << Contacts[id].getNickName() << std::endl;
            std::cout << "phone number : " << Contacts[id].getPhoneNumber() << std::endl;
            std::cout << "darkest secret : " << Contacts[id].getDarkestSecret() << std::endl;
        }
        else
            std::cout << "Index is not available" << std::endl;
    }
}

void PhoneBook::setContactsCount(int newCount)
{
    ContactsCount = newCount;
}

int PhoneBook::getContactsCount(void)
{
    return ContactsCount;
}
