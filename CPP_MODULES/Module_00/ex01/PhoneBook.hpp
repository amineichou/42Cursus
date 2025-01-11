/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:40:39 by moichou           #+#    #+#             */
/*   Updated: 2024/11/10 18:19:00 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
    int ContactsCount;
    Contact Contacts[8];

public:
    PhoneBook();
    ~PhoneBook();
    void addContact();
    void searchContacts();
    void setContactsCount(int newCount);
    int getContactsCount(void);
};

#endif