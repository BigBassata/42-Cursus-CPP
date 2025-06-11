/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:28:04 by licohen           #+#    #+#             */
/*   Updated: 2025/05/23 17:41:09 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <string>
#include <iostream>
#include <new>

class Zombie 
{
    private:
        std::string name;
        
    public:
    	Zombie(const std::string& name);
        ~Zombie();
        void announce( void );
};

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);