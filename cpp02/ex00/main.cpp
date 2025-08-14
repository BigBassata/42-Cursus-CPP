/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:56:08 by licohen           #+#    #+#             */
/*   Updated: 2025/08/11 15:52:03 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Fixed.hpp"

int main( void ) {
	Fixed a; // Constructeur par defaut
	Fixed b(a); // COnstructeur de copie
	Fixed c; // Nouveau constructeur par defaut
	Fixed d; // Encore un constructeur par defaut

	c = b; // Test : Operater d affectation
	d = a; // Test : Nouvel operateur d affectation
	
	std::cout << a.getRawBits() << std::endl; // Getter sur objet original
	std::cout << b.getRawBits() << std::endl; // Getter sur copie 
	std::cout << c.getRawBits() << std::endl; // Getter non assigne
	return (EXIT_SUCCESS);
}