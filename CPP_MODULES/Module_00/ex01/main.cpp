/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:14:19 by moichou           #+#    #+#             */
/*   Updated: 2024/11/21 11:13:15 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


void print_help(void)
{
    std::cout << "-----------------HOW TO USE-----------------" << std::endl;
    std::cout << "ADD    : save a new contact." << std::endl;
    std::cout << "SEARCH : display a specific contact." << std::endl;
    std::cout << "EXIT   : exit program." << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
}

int main(int ac, char **av)
{
    if (ac > 1)
    {
        std::cout << "Program args are not valid!" << std::endl;
        return 0;
    }
    (void)av;
    PhoneBook   MyPhoneBook;
    std::string cmd;

    print_help();

    while (true)
    {
        std::cout << "PHONE BOOK >> ";
        if (!std::getline(std::cin, cmd))
            break;
        else if (cmd == "ADD")
            MyPhoneBook.addContact();
        else if (cmd == "SEARCH")
            MyPhoneBook.searchContacts();
        else if (cmd == "EXIT")
            break;
        else
            print_help();
    }

    return 0;
}