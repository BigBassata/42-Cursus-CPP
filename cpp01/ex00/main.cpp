/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:26:47 by licohen           #+#    #+#             */
/*   Updated: 2025/05/23 17:46:47 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie *zombie1 = newZombie("Zombie1");
    zombie1->announce();
    Zombie *zombie2 = newZombie("Zombie2");
    zombie2->announce();
    delete zombie1;
    delete zombie2;
    std::cout << std::endl;
    randomChump("Zombie");
}