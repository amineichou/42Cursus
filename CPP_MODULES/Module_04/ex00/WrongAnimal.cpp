/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:40:45 by moichou           #+#    #+#             */
/*   Updated: 2025/01/07 16:44:12 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    this->type = "Default";
    std::cout << "WrongAnimal : Default constructor  called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal : Destructor constructor  called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &original)
{
    *this = original;
    std::cout << "WrongAnimal : Copy constructor  called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type)
{
    this->type = type;
    std::cout << "WrongAnimal : Paramiterized constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &second)
{
    if (this != &second)
    {
        this->type = second.type;
    }
    std::cout << "WrongAnimal : Copy assignment operator called" << std::endl;
    return *this;
}

std::string WrongAnimal::getType(void) const 
{
    return this->type;
}

std::ostream &operator<<(std::ostream &out, const WrongAnimal &A)
{
    out << A.getType();
    return out;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal Sound" << std::endl;
}