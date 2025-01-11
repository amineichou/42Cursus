/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 10:06:14 by moichou           #+#    #+#             */
/*   Updated: 2024/11/23 12:49:01 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
    int N  = 2;
    Zombie *tmp = zombieHorde(N, "amine");

    for (int i = 0; i < N; i++) {
        tmp[i].announce();
    }

    delete[] tmp;
    return 0;
}