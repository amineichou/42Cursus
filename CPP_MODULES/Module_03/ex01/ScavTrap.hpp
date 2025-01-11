/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:50:08 by moichou           #+#    #+#             */
/*   Updated: 2024/12/29 15:25:03 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
private:
    
public:
    ScavTrap();
    ScavTrap(const ScavTrap &original);
    ScavTrap(const std::string &name);
    ~ScavTrap();

    ScavTrap &operator=(const ScavTrap &second);

    void guardGate();

    void attack(const std::string &target);

};

#endif