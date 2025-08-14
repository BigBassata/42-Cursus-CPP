/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:31:24 by licohen           #+#    #+#             */
/*   Updated: 2025/08/11 17:07:54 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <cstdlib>
# include <iostream>
# include <cmath>

class Fixed
{
    private: 
        int                 _numberValue;
        static const int    fractionalBitsNb;
        
    public:
        Fixed(void);
        Fixed(const int intValue);
        Fixed(const float fValue);
        Fixed(const Fixed &other);
        Fixed& operator=(const Fixed& other);
        ~Fixed(void);

        int     toInt(void) const;
        float   toFloat(void) const;
        int     getRawBits(void) const;
        void    setRawBits(int const raw);

        bool    operator>(const Fixed& rhs) const;
        bool    operator<(const Fixed& rhs) const;
        bool    operator>=(const Fixed& rhs) const;
        bool    operator<=(const Fixed& rhs) const;
        bool    operator==(const Fixed& rhs) const;
        bool    operator!=(const Fixed& rhs) const;

        Fixed   operator+(const Fixed& rhs) const;
        Fixed   operator-(const Fixed& rhs) const;
        Fixed   operator*(const Fixed& rhs) const;
        Fixed   operator/(const Fixed& rhs) const;

        Fixed&  operator++(void);
        Fixed   operator++(int); 
        
  
        Fixed&  operator--(void);
        Fixed   operator--(int);

        static Fixed&       min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed&       max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed &fixed);

#endif