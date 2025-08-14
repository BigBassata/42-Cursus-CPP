/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:59:22 by licohen           #+#    #+#             */
/*   Updated: 2025/07/03 22:53:34 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : _name(name), _weapon(NULL)
{}

HumanB::~HumanB()
{}

void HumanB::attack() const
{
    if (_weapon)
        std::cout << _name << " attacks with their " << _weapon->getType() <<std::endl;
    else 
        std::cout << _name << " has no weapon ! " << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
        _weapon = &weapon;
}

