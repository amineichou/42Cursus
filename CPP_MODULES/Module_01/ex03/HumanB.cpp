/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:51:58 by moichou           #+#    #+#             */
/*   Updated: 2024/11/24 11:47:59 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string NNameB)
{
    WeaponB = NULL;
    NameB = NNameB;
}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &NWeaponB)
{
    WeaponB = &NWeaponB;
}

void HumanB::attack(void)
{
    std::cout << NameB << " attacks with their " << WeaponB->getType() << std::endl;
}