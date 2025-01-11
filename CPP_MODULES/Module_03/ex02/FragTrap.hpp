/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:33:41 by moichou           #+#    #+#             */
/*   Updated: 2024/12/29 17:43:24 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
private:

public:
    FragTrap();
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &original);
    ~FragTrap();

    FragTrap  &operator=(const FragTrap &second);
    void attack(const std::string &target);

    void highFivesGuys(void);
};
