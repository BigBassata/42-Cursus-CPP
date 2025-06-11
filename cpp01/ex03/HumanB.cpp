/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:52:47 by licohen           #+#    #+#             */
/*   Updated: 2025/06/03 16:35:38 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"


HumanB::HumanB(const std::string& humanName) : name(humanName), weapon(NULL)
{
}

HumanB::~HumanB()
{
}

void HumanB::attack() const
{
    if (weapon != NULL)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& newWeapon)
{
    weapon = &newWeapon;
}