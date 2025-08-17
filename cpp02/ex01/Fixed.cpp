/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liamcohen <liamcohen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:16:50 by licohen           #+#    #+#             */
/*   Updated: 2025/08/15 18:23:18 by liamcohen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionalBitsNb = 8;

Fixed::Fixed(void) : _numberValue(0)
{
    std::cout << "Default contructor called" << std::endl;
}

Fixed::Fixed(const int intValue) : _numberValue(intValue << fractionalBitsNb)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fValue) : _numberValue(roundf(fValue * (1 << fractionalBitsNb)))
{
    std::cout << "Float constructor called " << std::endl;
}

Fixed::Fixed(const Fixed &other) : _numberValue(other._numberValue)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_numberValue = other._numberValue;
    return *this;
}


Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::toInt(void) const
{
    return (_numberValue >> fractionalBitsNb);
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(_numberValue) / (1 << fractionalBitsNb));
}

int Fixed::getRawBits(void) const
{
    return (_numberValue);
}

void Fixed::setRawBits(int const raw)
{
    _numberValue = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}