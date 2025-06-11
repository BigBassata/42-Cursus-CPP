/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:52:49 by licohen           #+#    #+#             */
/*   Updated: 2025/06/03 16:41:22 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB
{
private:
    const std::string name;
    Weapon* weapon;

public:
    HumanB(const std::string& humanName);
    ~HumanB();
    void attack() const;
    void setWeapon(Weapon& newWeapon);
};

#endif