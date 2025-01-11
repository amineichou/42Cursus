/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:50:57 by moichou           #+#    #+#             */
/*   Updated: 2024/11/24 11:34:52 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
    std::string NameA;
    Weapon &WeaponA;

public:
    HumanA(std::string NNameA, Weapon &NWeaponA);
    ~HumanA();
    void setWeapon(Weapon weapon);
    void attack(void);

};

#endif