/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:03:01 by moichou           #+#    #+#             */
/*   Updated: 2025/01/07 19:01:34 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
public:
    Animal();
    Animal(const Animal &original);
    Animal(const std::string &type);
    virtual ~Animal();

    Animal &operator=(const Animal &original);

    std::string getType() const;

    virtual void makeSound() const;

protected:
    std::string type;

};

std::ostream &operator<<(std::ostream &out, const Animal &A);

#endif