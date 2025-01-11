/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:49:08 by moichou           #+#    #+#             */
/*   Updated: 2025/01/07 18:47:35 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include  "Cat.hpp"

int main()
{
    Dog *j = new Dog();
    // AAnimal test;

    Cat *i = new Cat();

    delete j;
    delete i;
    
    return 0;
}
