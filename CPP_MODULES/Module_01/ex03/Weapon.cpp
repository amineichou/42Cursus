/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:39:00 by moichou           #+#    #+#             */
/*   Updated: 2024/11/23 15:02:20 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string n_type)
{
    type = n_type;
}

Weapon::~Weapon() {}

std::string Weapon::getType(void) const
{
    return type;
}

void Weapon::setType(std::string n_type)
{
    type = n_type;
}