/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:14:32 by moichou           #+#    #+#             */
/*   Updated: 2024/12/30 18:14:50 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int fixedPoint;
    static const int fractionNumber;

public:
    Fixed();
    Fixed(const Fixed &obj);
    Fixed(const int iFixedPoint);
    Fixed(const float iFixedPoint);
    ~Fixed();

    Fixed operator=(const Fixed &obj);

    bool operator>(const Fixed &obj) const;
    bool operator<(const Fixed &obj) const;
    bool operator>=(const Fixed &obj) const;
    bool operator<=(const Fixed &obj) const;
    bool operator==(const Fixed &obj) const;
    bool operator!=(const Fixed &obj) const;

    float operator+(const Fixed &obj) const;
    float operator-(const Fixed &obj) const;
    float operator*(const Fixed &obj) const;
    float operator/(const Fixed &obj) const;

    Fixed operator++(void);
    Fixed operator++(int);

    int getRawBits() const;
    void setRawBits(int raw);
    float toFloat() const;
    int toInt() const;

    static const Fixed &min(const Fixed &one, const Fixed &two);
    static const Fixed &max(const Fixed &one, const Fixed &two);

    static const Fixed &min(Fixed &one, Fixed &two);
    static const Fixed &max(Fixed &one, Fixed &two);
};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);

#endif