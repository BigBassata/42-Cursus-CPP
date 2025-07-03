/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:59:28 by licohen           #+#    #+#             */
/*   Updated: 2025/06/30 18:20:58 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{}

Weapon::~Weapon()
{}

const std::string& Weapon::getType() const 
{
    return _type;
}

void Weapon::setType(std::string newType)
{
    _type = newType;
}