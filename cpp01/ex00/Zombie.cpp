/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 16:07:34 by licohen           #+#    #+#             */
/*   Updated: 2025/06/28 16:39:55 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(const std::string& name) : _name(name)
{
    std::cout << _name << " is created" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << _name << " is destroyed" << std::endl;
}

void Zombie::annonce()
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
