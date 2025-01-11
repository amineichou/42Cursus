/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:13:43 by moichou           #+#    #+#             */
/*   Updated: 2025/01/07 18:23:09 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; i++)
    {
        this->ideas[i] = "brilliant";
    }
    std::cout << "Brain : Constructor called" << std::endl;
}
Brain::Brain(const Brain &original)
{
    *this = original;
    std::cout << "Brain : Copy constructor called" << std::endl;
}
Brain::~Brain()
{
    std::cout << "Brain : Destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &second)
{
    std::cout << "Brain : Copy assignment operator called" << std::endl;
    if (this != &second)
    {
        for (int i = 0; i < 100; i++)
        {
            this->ideas[i] = second.ideas[i];
        }
    }
    return *this;
}