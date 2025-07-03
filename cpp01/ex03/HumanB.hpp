/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:59:24 by licohen           #+#    #+#             */
/*   Updated: 2025/07/02 20:37:34 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
    public:
        HumanB(const std::string& name);
        ~HumanB();
        void attack() const;
        void setWeapon(Weapon& weapon);
        
    private:
        std::string _name;
        Weapon* _weapon;
    
};

#endif