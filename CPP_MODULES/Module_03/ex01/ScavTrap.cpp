/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:41:29 by moichou           #+#    #+#             */
/*   Updated: 2025/01/01 17:41:32 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->setName("noName");
    this->setHitPoint(100);
    this->setEnergyPoint(50);
    this->setAttackDamage(20);
    std::cout << "ScavTrap : Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &original) : ClapTrap(original)
{
    *this = original;
    std::cout << "ScavTrap : Copy constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name)
{
    this->setName(name);
    this->setHitPoint(100);
    this->setEnergyPoint(50);
    this->setAttackDamage(20);
    std::cout << "ScavTrap : Parameterized constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap : Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &second)
{
    if (this != &second)
    {
        this->setName(second.getName());
        this->setEnergyPoint(second.getEnergyPoint());
        this->setHitPoint(second.getHitPoint());
        this->setAttackDamage(second.getAttackDamage());
    }
    std::cout << "ScavTrap : Copy assignment operator called" << std::endl;
    return *this;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->getEnergyPoint() <= 0 || this->getHitPoint() <= 0)
    {
        std::cout << "ScavTrap " << this->getName() << "has no energy to make an attack to target " << target << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << 1 << " points of damage!" << std::endl;
    unsigned int currEenergyPoint = this->getEnergyPoint();
    this->setEnergyPoint(currEenergyPoint--);
}


void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode." << std::endl;
}