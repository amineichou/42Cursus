/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:34:37 by moichou           #+#    #+#             */
/*   Updated: 2025/01/07 08:00:22 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "Cat : Default constructor called" << std::endl;
}

Cat::Cat(const Cat &original) : Animal(original)
{
    *this = original;
    std::cout << "Cat : Copy constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat : istructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &second)
{
    if (this != &second)
    {
        this->type = second.type;
    }
    return *this;
}
    
void Cat::makeSound() const
{
    std::cout << "Meaw" << std::endl;
}

