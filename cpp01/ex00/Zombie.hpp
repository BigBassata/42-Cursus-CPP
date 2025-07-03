/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:51:55 by licohen           #+#    #+#             */
/*   Updated: 2025/07/02 20:37:26 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <new>

class Zombie
{
    public:
        Zombie(const std::string& name);
        ~Zombie();
        void annonce(void);
        
    private:
        std::string _name;
    
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);
