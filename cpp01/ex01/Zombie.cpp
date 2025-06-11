/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:10:29 by licohen           #+#    #+#             */
/*   Updated: 2025/05/28 15:01:10 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() 
{
}

Zombie::Zombie(std::string name) : _name(name) 
{
}

Zombie::~Zombie()
{
    std::cout << _name << " has been destroyed." << std::endl; 
}

void Zombie::setName(std::string newName)
{
    this->_name = newName;
}

void Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}