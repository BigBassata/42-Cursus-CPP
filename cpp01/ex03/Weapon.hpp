/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:52:35 by licohen           #+#    #+#             */
/*   Updated: 2025/06/03 16:40:07 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
    private:
        std::string type;
    
    public:
        Weapon(std::string weaponType);
        ~Weapon();
        void setType(std::string typeName);
        const std::string& getType() const;
};

#endif