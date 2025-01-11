/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:10:44 by moichou           #+#    #+#             */
/*   Updated: 2024/12/21 16:52:12 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(int ac, char *av[])
{
    if (ac != 4)
    {
        std::cout << "No valid args.\n";
        return 1;
    }

    std::ifstream MainFile(av[1]);
    std::string ResString, line;
    if (MainFile.is_open())
    {
        while (std::getline(MainFile, line))
        {
            ResString += replaceStr(line, av[2], av[3]);
            if (!MainFile.eof())
                ResString += "\n";
        }
    }
    else
    {
        std::cout << "no file or no valid permissions for the file \"" << av[1] << "\", try to create it or add valid permissions." << std::endl;
        return 1;
    }

    std::string fileName = av[1];
    fileName += ".replace";
    std::ofstream ReplacedFile(fileName.c_str());
    if (ReplacedFile.is_open())
    {
        ReplacedFile << ResString;
    }
    else
    {
        MainFile.close();
        std::cout << "no file or no valid permissions for the file \"" << av[2] << "\", try to create it or add valid permissions." << std::endl;
        return 1;
    }

    MainFile.close();
    ReplacedFile.close();
    return 0;
}