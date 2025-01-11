/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:01:59 by moichou           #+#    #+#             */
/*   Updated: 2024/12/22 16:14:30 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump( std::string name ) 
{
    Zombie *newOne = new(std::nothrow) Zombie;
    if (newOne == NULL)
    {
        std::cout << "failed to allocate memory !" << std::endl;
        exit(1);
    }
    newOne->setName(name);
    newOne->announce();
    delete newOne;
}