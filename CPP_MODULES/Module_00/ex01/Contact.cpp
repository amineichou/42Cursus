/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:46:09 by moichou           #+#    #+#             */
/*   Updated: 2024/11/10 18:23:45 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact(){}
Contact::~Contact(){}

std::string Contact::getFirstName(void) const
{
    return FirstName;
}

std::string Contact::getLastName(void) const
{
    return LastName;
}

std::string Contact::getNickName(void) const
{
    return NickName;
}

std::string Contact::getPhoneNumber(void) const
{
    return PhoneNumber;
}

std::string Contact::getDarkestSecret(void) const
{
    return DarkestSecret;
}

int Contact::getIndex(void) const
{
    return index;
}

void Contact::setFirstName(std::string firstName)
{
    FirstName = firstName;
}

void Contact::setLastName(std::string lastName)
{
    LastName = lastName;
}

void Contact::setNickName(std::string nickName)
{
    NickName = nickName;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
    PhoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret)
{
    DarkestSecret = darkestSecret;
}

void Contact::setIndex(int newIndex)
{
    index = newIndex;
}
