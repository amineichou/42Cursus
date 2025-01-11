/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:35:28 by moichou           #+#    #+#             */
/*   Updated: 2024/12/30 17:34:32 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP


#include <iostream>
#include <string>


class ClapTrap {
private:
    std::string name;
    unsigned int hitPoint;
    unsigned int energyPoint;
    unsigned int attackDamage;

public:
    ClapTrap();
    ClapTrap(const std::string &nname);
    ClapTrap(const ClapTrap &original);
    ClapTrap &operator=(const ClapTrap &second);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    std::string getName(void) const;
    unsigned int getHitPoint(void) const;
    unsigned int getEnergyPoint(void) const;
    unsigned int getAttackDamage(void) const;

    void setName(std::string i_name);
    void setHitPoint(unsigned int amount);
    void setEnergyPoint(unsigned int amount);
    void setAttackDamage(unsigned int amount);
};


#endif