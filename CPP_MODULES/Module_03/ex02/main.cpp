/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 12:13:31 by moichou           #+#    #+#             */
/*   Updated: 2025/01/01 15:36:27 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	FragTrap a("moichou");
	FragTrap b("zyamli");
	FragTrap c(a);
    FragTrap d("skarim");

    
    a.attack("skarim");
    d.takeDamage(a.getAttackDamage());
    
    b.attack("moichou");
    a.takeDamage(b.getAttackDamage());

    
    c.beRepaired(10);

    a.highFivesGuys();

    d.highFivesGuys();

    return 0;
}