/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:44:19 by moichou           #+#    #+#             */
/*   Updated: 2025/01/07 16:54:52 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << "WrongCat : Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &original) : WrongAnimal(original)
{
    *this = original;
    std::cout << "WrongCat : Copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat : distructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &second)
{
    if (this != &second)
    {
        this->type = second.type;
    }
    return *this;
}
    
void WrongCat::makeSound() const
{
    std::cout << "Meaw" << std::endl;
}
