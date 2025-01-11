/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:55:21 by moichou           #+#    #+#             */
/*   Updated: 2024/11/24 11:48:03 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"

class HumanB
{
private:
    std::string NameB;
    Weapon *WeaponB;

public:
    HumanB(std::string NNameB);
    ~HumanB();
    void setWeapon(Weapon &NWeaponB);
    void attack(void);
};

#endif