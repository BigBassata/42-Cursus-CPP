/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:31:26 by licohen           #+#    #+#             */
/*   Updated: 2025/08/11 17:06:47 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Initialize the static constant member
const int Fixed::fractionalBitsNb = 8;

// ========== ORTHODOX CANONICAL FORM ==========
// These functions are identical to exercise 01

Fixed::Fixed(void) : _numberValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue) : _numberValue(intValue << fractionalBitsNb)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fValue) : _numberValue(roundf(fValue * (1 << fractionalBitsNb)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : _numberValue(other._numberValue)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_numberValue = other._numberValue;
    }
    return *this;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

// ========== CONVERSION FUNCTIONS ==========
// These functions are identical to exercise 01

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

// ========== COMPARISON OPERATORS ==========
// These operators compare the internal fixed-point representations directly
// Since both operands use the same scale (256), direct comparison works perfectly

bool Fixed::operator>(const Fixed& rhs) const
{
    return this->_numberValue > rhs._numberValue;
}

bool Fixed::operator<(const Fixed& rhs) const
{
    return this->_numberValue < rhs._numberValue;
}

bool Fixed::operator>=(const Fixed& rhs) const
{
    return this->_numberValue >= rhs._numberValue;
}

bool Fixed::operator<=(const Fixed& rhs) const
{
    return this->_numberValue <= rhs._numberValue;
}

bool Fixed::operator==(const Fixed& rhs) const
{
    return this->_numberValue == rhs._numberValue;
}

bool Fixed::operator!=(const Fixed& rhs) const
{
    return this->_numberValue != rhs._numberValue;
}

// ========== ARITHMETIC OPERATORS ==========
// These operators perform arithmetic on fixed-point numbers
// Key insight: addition and subtraction work directly on internal values
// but multiplication and division require scale adjustments

Fixed Fixed::operator+(const Fixed& rhs) const
{
    Fixed result;
    // Direct addition works because both numbers have same scale factor
    result._numberValue = this->_numberValue + rhs._numberValue;
    return result;
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
    Fixed result;
    // Direct subtraction works because both numbers have same scale factor
    result._numberValue = this->_numberValue - rhs._numberValue;
    return result;
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
    Fixed result;
    // Multiplication requires careful handling of scale factor
    // When you multiply two scaled numbers, the result is double-scaled
    // So we need to divide by the scale factor once to get back to single scale
    result._numberValue = (this->_numberValue * rhs._numberValue) >> fractionalBitsNb;
    return result;
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
    Fixed result;
    // Division requires careful handling of scale factor
    // When dividing scaled numbers, we need to maintain precision
    // So we scale up the dividend before division to compensate
    result._numberValue = (this->_numberValue << fractionalBitsNb) / rhs._numberValue;
    return result;
}

// ========== INCREMENT/DECREMENT OPERATORS ==========
// The smallest representable increment in our fixed-point system is 1 raw unit
// which represents 1/256 ≈ 0.00390625 in actual value

Fixed& Fixed::operator++(void)
{
    // Pre-increment: increment and return reference to self
    // Adding 1 to raw value means adding 1/256 to the actual value
    ++this->_numberValue;
    return *this;
}

Fixed Fixed::operator++(int)
{
    // Post-increment: save current value, increment self, return saved value
    // The int parameter is unused - it's just to distinguish from pre-increment
    Fixed temp(*this);
    ++this->_numberValue;
    return temp;
}

Fixed& Fixed::operator--(void)
{
    // Pre-decrement: decrement and return reference to self
    --this->_numberValue;
    return *this;
}

Fixed Fixed::operator--(int)
{
    // Post-decrement: save current value, decrement self, return saved value
    Fixed temp(*this);
    --this->_numberValue;
    return temp;
}

// ========== STATIC MIN/MAX FUNCTIONS ==========
// These functions provide utility operations for finding minimum and maximum values
// We need both const and non-const versions to handle different usage contexts

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    // Return reference to the smaller of two Fixed objects
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    // Const version for when we're working with const Fixed objects
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    // Return reference to the larger of two Fixed objects
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    // Const version for when we're working with const Fixed objects
    return (a > b) ? a : b;
}

// ========== STREAM INSERTION OPERATOR ==========
// Non-member function that allows natural printing of Fixed objects

std::ostream& operator<<(std::ostream& os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}