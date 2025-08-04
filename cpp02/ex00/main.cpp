/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:56:08 by licohen           #+#    #+#             */
/*   Updated: 2025/07/15 13:43:31 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed b(a);
	Fixed c;
	Fixed d;

	c = b;
	d = a;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return (EXIT_SUCCESS);
}