/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:39:47 by moichou           #+#    #+#             */
/*   Updated: 2025/01/07 08:00:16 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP


#include "Animal.hpp"

class Dog : public Animal {
private:

public:
    Dog();
    Dog(const Dog &original);
    ~Dog();

    Dog &operator=(const Dog &second);

    void makeSound() const;
};


#endif