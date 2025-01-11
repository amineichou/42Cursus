/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:06:46 by moichou           #+#    #+#             */
/*   Updated: 2024/11/24 11:45:09 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string NNameA, Weapon &NWeaponA) : WeaponA(NWeaponA)
{
    NameA = NNameA;
}

HumanA::~HumanA() {}

void HumanA::setWeapon(Weapon NWeaponA)
{
    WeaponA = NWeaponA;
}

void HumanA::attack(void)
{
    std::cout << NameA << " attacks with their " << WeaponA.getType() << std::endl;
}