/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:02:57 by moichou           #+#    #+#             */
/*   Updated: 2025/01/03 19:48:51 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    this->type = "Default";
    std::cout << "AAnimal : Default constructor  called" << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal : Destructor constructor  called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &original)
{
    *this = original;
    std::cout << "AAnimal : Copy constructor  called" << std::endl;
}

AAnimal::AAnimal(const std::string &type)
{
    this->type = type;
    std::cout << "AAnimal : Paramiterized constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &second)
{
    if (this != &second)
    {
        this->type = second.type;
    }
    std::cout << "AAnimal : Copy assignment operator called" << std::endl;
    return *this;
}

std::string AAnimal::getType(void) const 
{
    return this->type;
}

std::ostream &operator<<(std::ostream &out, const AAnimal &A)
{
    out << A.getType();
    return out;
}

void AAnimal::makeSound() const
{
    std::cout << "AAnimal is making sound" << std::endl;
}