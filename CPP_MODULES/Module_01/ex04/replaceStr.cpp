/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceStr.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:08:34 by moichou           #+#    #+#             */
/*   Updated: 2024/11/24 12:37:56 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

std::string replaceStr(std::string line, std::string toRep, std::string rep)
{
    if (toRep.empty()) return line;

    size_t position = line.find(toRep);
    std::string res;
    
    while (position != std::string::npos)
    {
        res += line.substr(0, position) + rep;
        line = line.substr(position + toRep.length());
        position = line.find(toRep);
    }

    res += line;
    return res;
}