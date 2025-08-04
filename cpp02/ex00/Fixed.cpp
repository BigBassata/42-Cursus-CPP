/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:56:03 by licohen           #+#    #+#             */
/*   Updated: 2025/08/04 16:25:55 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*  Initialisation du membre statique
    Definition du membre statique en dehors de la classe. La syntaxe Fixed:: 
    indique que l on defint le membre fractionalBitsNb de la classe Fixed.*/
const int	Fixed::fractionalBitsNb = 8;

/*  Constructeur par defaut:
    - Liste d initialisation -> : _numberValue(0)
    C est la facon correcte d init les membres en C++.
    - Messsage de debug. Ils aident a mieux comprendre quand chaque constructeur est appele. 
    - Init a 0, en virgule fixe, 0 represente vraiment 0,0 donc c est logique.*/
Fixed::Fixed(void) : _numberValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

/*  Constructeur de copie:
    Copie profonde vs Copie superficielle, ici nous n avons qu un entier, la copie membre 
	par membre suffit, on copie directement la vlaeur de other._numberValue dans le nouvel objet. 
	On accede a other._numberValue meme si c est privee car nous sommes dans un methode de classe.
	*/
Fixed::Fixed(const Fixed &other) : _numberValue(other._numberValue) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_numberValue = other._numberValue;
	}
	return (*this);
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_numberValue);
}

void	Fixed::setRawBits(int const raw) {
	_numberValue = raw;
}