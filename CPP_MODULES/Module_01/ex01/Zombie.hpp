/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 10:06:20 by moichou           #+#    #+#             */
/*   Updated: 2024/12/21 13:24:23 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <cstdlib>

class Zombie {
private:
    std::string name;

public:
    Zombie();
    ~Zombie();
    void announce(void);
    void setName(std::string newName);
};

Zombie* zombieHorde( int N, std::string name );

#endif