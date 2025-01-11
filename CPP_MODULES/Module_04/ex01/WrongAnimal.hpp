/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:41:01 by moichou           #+#    #+#             */
/*   Updated: 2025/01/07 16:51:39 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL
#define WRONGANIMAL

#include <iostream>
#include <string>

class WrongAnimal {
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &original);
    WrongAnimal(const std::string &type);
    virtual ~WrongAnimal();

    WrongAnimal &operator=(const WrongAnimal &original);

    std::string getType() const;

    void makeSound() const;

protected:
    std::string type;
};

std::ostream &operator<<(std::ostream &out, const WrongAnimal &A);

#endif