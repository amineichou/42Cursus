/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 12:13:31 by moichou           #+#    #+#             */
/*   Updated: 2025/01/01 17:47:18 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a("moichou");
    ClapTrap b("zyamli");
    ClapTrap c(a);
    ClapTrap d;
    d = c;

    a.attack("skarim");
    b.takeDamage(a.getAttackDamage());
    a.attack("skarim");
    b.takeDamage(a.getAttackDamage());
    a.attack("skarim");
    a.attack("skarim");
    a.attack("skarim");
    a.attack("skarim");
    a.attack("skarim");
    a.attack("skarim");
    a.attack("skarim");
    a.attack("skarim");
    a.attack("skarim");
    a.attack("skarim");
    a.attack("skarim");

    a.beRepaired(10);

    b.attack("moichou");
    a.takeDamage(b.getAttackDamage());
    c.beRepaired(10);

    return 0;
}