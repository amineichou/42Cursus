/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:34:37 by moichou           #+#    #+#             */
/*   Updated: 2025/01/07 18:24:02 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    this->brain = new Brain;
    std::cout << "Cat : Default constructor called" << std::endl;
}

Cat::Cat(const Cat &original) : Animal(original)
{
    this->brain = NULL;
    *this = original;
    std::cout << "Cat : Copy constructor called" << std::endl;
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat : Destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &second)
{
    std::cout << "Cat : Copy assignment operator called" << std::endl;
    if (this != &second)
    {
        Animal::operator=(second);
        delete this->brain;
        if (second.brain)
            this->brain = new Brain(*second.brain);
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meaw" << std::endl;
}

