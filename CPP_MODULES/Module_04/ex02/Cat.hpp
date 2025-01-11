/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:32:36 by moichou           #+#    #+#             */
/*   Updated: 2025/01/07 08:01:09 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
private:
    Brain *brain;
public:
    Cat();
    Cat(const Cat &original);
    ~Cat();

    Cat &operator=(const Cat &second);

    void makeSound() const;

    std::string getType(void) const;
};

#endif