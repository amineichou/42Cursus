/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:39:00 by moichou           #+#    #+#             */
/*   Updated: 2025/01/07 18:22:50 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog : Default constructor called" << std::endl;
}

Dog::Dog(const Dog &original) : AAnimal(original)
{
    this->brain = new Brain(*original.brain); // Deep copy of Brain
    this->type = original.type;
    std::cout << "Dog : Copy constructor called" << std::endl;
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog : Destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &second)
{
    std::cout << "Dog : Copy assignment operator called" << std::endl;
    if (this != &second)
    {
        AAnimal::operator=(second);
        delete this->brain;
        if (second.brain)
            this->brain = new Brain(*second.brain);
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof woof" << std::endl;
}

std::string Dog::getType(void) const 
{
    return this->type;
}