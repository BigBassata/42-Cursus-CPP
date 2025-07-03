/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:59:10 by licohen           #+#    #+#             */
/*   Updated: 2025/06/30 18:58:45 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) : _name(name), _weapon(weapon) 
{}

HumanA::~HumanA()
{}

void HumanA::attack() const
{
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}