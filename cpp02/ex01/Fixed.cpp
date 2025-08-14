/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:16:50 by licohen           #+#    #+#             */
/*   Updated: 2025/08/11 16:27:31 by licohen          ###   ########.fr       */
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
    return this->_numberValue >> fractionalBitsNb;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(this->_numberValue) / (1 << fractionalBitsNb);
}

int Fixed::getRawBits(void) const
{
    return this->_numberValue;
}

void Fixed::setRawBits(int const raw)
{
    this->_numberValue = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}