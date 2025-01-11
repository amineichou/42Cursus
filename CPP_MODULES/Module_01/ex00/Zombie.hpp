/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:59:45 by moichou           #+#    #+#             */
/*   Updated: 2024/12/21 10:15:25 by moichou          ###   ########.fr       */
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


Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif