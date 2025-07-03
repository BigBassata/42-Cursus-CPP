/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:59:18 by licohen           #+#    #+#             */
/*   Updated: 2025/06/30 19:08:54 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
    public:
        HumanA(const std::string& name, Weapon& weapon);
        ~HumanA();
        void attack() const;
        
    private:
        std::string _name;
        Weapon& _weapon;
    
};

#endif