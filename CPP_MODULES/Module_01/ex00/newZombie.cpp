/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:01:36 by moichou           #+#    #+#             */
/*   Updated: 2024/11/23 11:27:38 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie *newOne = new(std::nothrow) Zombie;
    if (newOne == NULL)
    {
        std::cout << "failed to allocate memory !" << std::endl;
        exit(1);
    }
    newOne->setName(name);
    return newOne;
}