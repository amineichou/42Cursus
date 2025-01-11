/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:08:30 by moichou           #+#    #+#             */
/*   Updated: 2024/12/27 18:09:40 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionNumber = 8;

Fixed::Fixed() {
    this->fixedPoint = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj) {
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

Fixed::Fixed(const int iFixedPoint) {
    fixedPoint = iFixedPoint << fractionNumber;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float iFixedPoint) {
    fixedPoint = roundf(iFixedPoint * (1 << fractionNumber));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &obj) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj) {
        fixedPoint = obj.fixedPoint;
    }
    return *this;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return fixedPoint;
}

void Fixed::setRawBits(int raw) {
    fixedPoint = raw;
}

float Fixed::toFloat() const {
    return (float)(fixedPoint) / (1 << fractionNumber);
}

int Fixed::toInt() const {
    return fixedPoint >> fractionNumber;
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj) {
    out << obj.toFloat();
    return out;
}
