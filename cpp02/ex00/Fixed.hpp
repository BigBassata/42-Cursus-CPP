/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liamcohen <liamcohen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:56:05 by licohen           #+#    #+#             */
/*   Updated: 2025/08/15 18:26:09 by liamcohen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <cstdlib>
# include <iostream>

class Fixed 
{
	private:
	    int					_numberValue;
	    static const int	fractionalBitsNb;
 
	public:
        Fixed(void);
        Fixed(const Fixed &other);
        Fixed& operator=(const Fixed& other);
        ~Fixed(void);
        int		getRawBits(void) const;
        void	setRawBits(int const raw);
};

#endif