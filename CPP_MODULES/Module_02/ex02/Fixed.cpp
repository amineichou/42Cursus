/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:55:38 by moichou           #+#    #+#             */
/*   Updated: 2024/12/30 18:14:44 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionNumber = 8;

Fixed::Fixed() {
    this->fixedPoint = 0;
}

Fixed::Fixed(const Fixed &obj) {
    *this = obj;
}

Fixed::Fixed(const int iFixedPoint) {
    this->fixedPoint = iFixedPoint << fractionNumber;
}

Fixed::Fixed(const float iFixedPoint) {
    this->fixedPoint = roundf(iFixedPoint * (1 << this->fractionNumber));
}

Fixed::~Fixed() {}

Fixed Fixed::operator=(const Fixed &obj) {
    if (this != &obj) {
        fixedPoint = obj.fixedPoint;
    }
    return *this;
}

int Fixed::getRawBits() const {
    return fixedPoint;
}

void Fixed::setRawBits(int raw) {
    fixedPoint = raw;
}

float Fixed::toFloat() const {
    return (float)fixedPoint / (1 << fractionNumber);
}

int Fixed::toInt() const {
    return fixedPoint >> fractionNumber;
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj) {
    out << obj.toFloat();
    return out;
}

// comparison

bool Fixed::operator>(const Fixed &obj) const
{
    return this->toFloat() > obj.toFloat();
}

bool Fixed::operator<(const Fixed &obj) const
{
    return this->toFloat() < obj.toFloat();
}

bool Fixed::operator>=(const Fixed &obj) const
{
    return this->toFloat() >= obj.toFloat();
}

bool Fixed::operator<=(const Fixed &obj) const
{
    return this->toFloat() <= obj.toFloat();
}

bool Fixed::operator==(const Fixed &obj) const
{
    return this->toFloat() == obj.toFloat();
}

bool Fixed::operator!=(const Fixed &obj) const
{
    return this->toFloat() != obj.toFloat();
}

// operations

float Fixed::operator+(const Fixed &obj) const
{
    return this->toFloat() + obj.toFloat();
}

float Fixed::operator-(const Fixed &obj) const
{
    return this->toFloat() - obj.toFloat();
}

float Fixed::operator*(const Fixed &obj) const
{
    return this->toFloat() * obj.toFloat();
}

float Fixed::operator/(const Fixed &obj) const
{
    return this->toFloat() / obj.toFloat();
}

// postfix Increment
Fixed Fixed::operator++(void) {
    this->fixedPoint++;
    return *this;
}

// prefix Increment
Fixed Fixed::operator++(int) {
    Fixed tmp(this->toFloat());
    this->fixedPoint++;
    return tmp;
}

const Fixed &Fixed::min(const Fixed &one, const Fixed &two)
{
    if (one.getRawBits() > two.getRawBits())
        return two;
    return one;
}

const Fixed &Fixed::max(const Fixed &one, const Fixed &two)
{
    if (one.getRawBits() < two.getRawBits())
        return two;
    return one;
}

const Fixed &Fixed::min(Fixed &one, Fixed &two)
{
    if (one.getRawBits() > two.getRawBits())
        return two;
    return one;
}

const Fixed &Fixed::max(Fixed &one, Fixed &two)
{
    if (one.getRawBits() < two.getRawBits())
        return two;
    return one;
}