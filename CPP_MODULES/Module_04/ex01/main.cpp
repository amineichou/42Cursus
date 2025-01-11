/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:49:08 by moichou           #+#    #+#             */
/*   Updated: 2025/01/07 18:25:13 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const Animal *j = new Dog();
    const Animal *i = new Cat();



    delete j; // should not create a leak
    delete i;


    Animal *Array[6];

    for (int i = 0; i < 3; i++)
    {
        Array[i] = new Dog();
    }
    
    for (int i = 3; i < 6; i++)
    {
        Array[i] = new Cat();
    }

    
    for (int i = 0; i < 3; i++)
    {
        delete Array[i];
    }
    
    for (int i = 3; i < 6; i++)
    {
        delete Array[i];
    }
    Animal *a = new Dog();
    Animal *b = new Dog();

    *a = *b;

    delete a;
    delete b;

    return 0;
}
