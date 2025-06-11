/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:52:45 by licohen           #+#    #+#             */
/*   Updated: 2025/06/03 16:35:16 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& humanName, Weapon& humanWeapon) : name(humanName), weapon(humanWeapon)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack() const
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}