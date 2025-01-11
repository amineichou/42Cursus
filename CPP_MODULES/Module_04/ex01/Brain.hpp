/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:02:52 by moichou           #+#    #+#             */
/*   Updated: 2025/01/07 18:05:29 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>


class Brain {
private:
    std::string ideas[100];

public:
    Brain();
    Brain(const Brain &original);
    ~Brain();

    Brain &operator=(const Brain &second);
};



#endif