/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:44:19 by moichou           #+#    #+#             */
/*   Updated: 2025/01/07 18:43:35 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    this->brain = new Brain;
    std::cout << "WrongCat : Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &original) : WrongAnimal(original)
{
    *this = original;
    std::cout << "WrongCat : Copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    delete this->brain;
    std::cout << "WrongCat : distructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &second)
{
    std::cout << "WrongCat : Copy assignment operator called" << std::endl;
    if (this != &second)
    {
        WrongAnimal::operator=(second);
        delete this->brain;
        if (second.brain)
            this->brain = new Brain(*second.brain);
    }
    return *this;
}
    
void WrongCat::makeSound() const
{
    std::cout << "Meaw" << std::endl;
}

std::string WrongCat::getType(void) const 
{
    return this->type;
}