/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 12:13:31 by moichou           #+#    #+#             */
/*   Updated: 2025/01/01 15:32:40 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap a("moichou");
	ScavTrap b("zyamli");
	ScavTrap c(a);
    ScavTrap d("skarim");

    
    a.attack("skarim");
    d.takeDamage(a.getAttackDamage());

    b.attack("moichou");
    a.takeDamage(b.getAttackDamage());

    a.beRepaired(10);

    d.guardGate();

    return 0;
}