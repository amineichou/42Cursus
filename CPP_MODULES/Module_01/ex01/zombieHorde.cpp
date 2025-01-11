/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 10:14:58 by moichou           #+#    #+#             */
/*   Updated: 2024/11/23 12:47:51 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
    if (N <= 0)
    {
        std::cout << "N is not valid value!" << std::endl;
        exit(1);
    }

    Zombie *allZombies = new(std::nothrow) Zombie[N];

    if (!allZombies)
    {
        std::cout << "failed to allocate memory !" << std::endl;
        exit(1);
    }

    for (int i = 0; i < N; i++) {
        allZombies[i].setName(name);
    }

    return allZombies;
}