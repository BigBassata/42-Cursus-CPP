/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:59:30 by licohen           #+#    #+#             */
/*   Updated: 2025/07/02 20:37:36 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
    public:
        Weapon(std::string type);
        ~Weapon();
        const std::string& getType() const;
        void setType(std::string newType);
        
    private:
        std::string _type;

};

#endif