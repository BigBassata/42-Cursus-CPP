/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:52:42 by licohen           #+#    #+#             */
/*   Updated: 2025/06/03 16:41:11 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA
{
private: 
    std::string name;
    Weapon& weapon;        

public:
    HumanA(const std::string& humanName, Weapon& humanWeapon);       
    ~HumanA();
    void attack() const;
};

#endif