/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:10:37 by licohen           #+#    #+#             */
/*   Updated: 2025/05/28 14:38:03 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>

class Zombie 
{
private:
    std::string _name; 
public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    void setName(std::string newName);
    void announce(void);
};

Zombie* zombieHorde( int N, std::string name );
void	destroyHorde(Zombie *horde);
