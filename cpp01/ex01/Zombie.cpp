/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:10:21 by licohen           #+#    #+#             */
/*   Updated: 2025/06/28 19:04:24 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << "A zombie is created" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << _name << " is destroyed" << std::endl;
}

void Zombie::setName(const std::string& name) 
{
    _name = name;
}

void Zombie::announce()
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
