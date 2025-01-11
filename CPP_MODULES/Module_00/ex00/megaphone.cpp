/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:41:34 by moichou           #+#    #+#             */
/*   Updated: 2024/11/09 19:04:57 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else if (ac >= 2)
    {
        for (int j = 1; j < ac; j++)
        {
            std::string input = av[j];
            for (int i = 0; input[i] != '\0'; i++)
            {
                input[i] = std::toupper(input[i]);
            }
            std::cout << input;
        }
    }
    std::cout << std::endl;
}
