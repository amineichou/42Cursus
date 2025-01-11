/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:59:25 by moichou           #+#    #+#             */
/*   Updated: 2024/11/23 11:55:23 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    {
        Zombie first;
        first.setName("first");
        first.announce();
    }

    {
        Zombie *second = newZombie("second");
        second->announce();
        delete second;
    }

    {
        randomChump("last");
    }
}