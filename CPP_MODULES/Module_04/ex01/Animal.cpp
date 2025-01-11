/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:02:57 by moichou           #+#    #+#             */
/*   Updated: 2025/01/06 23:02:06 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    this->type = "Default";
    std::cout << "Animal : Default constructor  called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal : Destructor constructor  called" << std::endl;
}

Animal::Animal(const Animal &original)
{
    *this = original;
    std::cout << "Animal : Copy constructor  called" << std::endl;
}

Animal::Animal(const std::string &type)
{
    this->type = type;
    std::cout << "Animal : Paramiterized constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &second)
{
    if (this != &second)
    {
        this->type = second.type;
    }
    std::cout << "Animal : Copy assignment operator called" << std::endl;
    return *this;
}

std::string Animal::getType(void) const
{
    return this->type;
}

std::ostream &operator<<(std::ostream &out, const Animal &A)
{
    out << A.getType();
    return out;
}

void Animal::makeSound() const
{
    std::cout << "animal is making sound" << std::endl;
}