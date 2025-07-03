/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:03:33 by licohen           #+#    #+#             */
/*   Updated: 2025/06/28 19:07:20 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>

class Zombie
{
    public:
        Zombie();
        ~Zombie();
        void announce();
        void setName(const std::string& name);

    private:
        std::string _name;
    
};

Zombie* zombieHorde(int N, std::string name);
void destroyHorde(Zombie* horde);