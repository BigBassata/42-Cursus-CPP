/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:52:37 by licohen           #+#    #+#             */
/*   Updated: 2025/06/03 15:09:57 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weaponType) : type(weaponType)
{
}

Weapon::~Weapon()
{
}

void Weapon::setType(std::string typeName) 
{
    type = typeName;
}

const std::string& Weapon::getType() const 
{
    return type;
}

