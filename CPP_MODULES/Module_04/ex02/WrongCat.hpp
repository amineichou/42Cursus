/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:44:50 by moichou           #+#    #+#             */
/*   Updated: 2025/01/07 18:43:58 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT
#define WRONGCAT

#include "WrongAnimal.hpp"
#include "Brain.hpp"

class WrongCat : public WrongAnimal {
private:
    Brain *brain;
public:
    WrongCat();
    WrongCat(const WrongCat &original);
    ~WrongCat();

    WrongCat &operator=(const WrongCat &second);

    std::string getType(void) const;

    void makeSound() const;
};


#endif