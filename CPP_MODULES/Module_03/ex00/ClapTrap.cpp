/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:42:05 by moichou           #+#    #+#             */
/*   Updated: 2025/01/01 16:03:28 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    this->name = "noName";
    this->hitPoint = 10;
    this->energyPoint = 10;
    this->attackDamage = 0;
    std::cout << "ClapTrap : Default constructor called" << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap &original)
{
    std::cout << "ClapTrap : Copy constructor called" << std::endl;
    *this = original;
}

ClapTrap::ClapTrap(const std::string &nname)
{
    this->name = nname;
    this->hitPoint = 10;
    this->energyPoint = 10;
    this->attackDamage = 0;
    std::cout << "ClapTrap : Parameterized constructor called" << std::endl;
}


ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap : Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->energyPoint == 0)
    {
        std::cout << "ClapTrap " << this->name << " has no energy left to make an attack!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
    this->energyPoint--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoint <= 0 || this->energyPoint <= 0)
    {
        std::cout << "ClapTrap " << this->name << " is out of energy points or hit points." << std::endl;
        return;
    }
    if (this->hitPoint <= amount)
        this->hitPoint = 0;
    else
        this->hitPoint -= amount;
    std::cout << "ClapTrap " << this->name << " took " << amount << " of hit points." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energyPoint <= 0)
    {
        std::cout << "ClapTrap " << this->name << " is out of energy and can't be repaired." << std::endl;
        return;
    }
    this->energyPoint--;
    this->hitPoint += amount;
    std::cout << "ClapTrap " << this->name << " is repaired using one of enegy point." << std::endl;
}


ClapTrap &ClapTrap::operator=(const ClapTrap &second)
{
    if (this != &second)
    {
        this->name = second.name;
        this->energyPoint = second.energyPoint;
        this->hitPoint = second.hitPoint;
        this->attackDamage = second.attackDamage;
    }
    std::cout << "ClapTrap : Copy assignment operator called" << std::endl;
    return *this;
}

// getters
std::string ClapTrap::getName(void) const
{
    return this->name;
}

unsigned int ClapTrap::getHitPoint(void) const
{
    return this->hitPoint;
}

unsigned int ClapTrap::getEnergyPoint(void) const
{
    return this->energyPoint;
}

unsigned int ClapTrap::getAttackDamage(void) const
{
    return this->attackDamage;
}

// setters

void ClapTrap::setName(std::string i_name)
{
    this->name = i_name;
}

void ClapTrap::setHitPoint(unsigned int amount)
{
    this->hitPoint = amount;
}

void ClapTrap::setEnergyPoint(unsigned int amount)
{
    this->energyPoint = amount;
}

void ClapTrap::setAttackDamage(unsigned int amount)
{
    this->attackDamage = amount;
}