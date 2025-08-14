/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 16:32:22 by licohen           #+#    #+#             */
/*   Updated: 2025/07/03 21:37:59 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie* zombie1 = newZombie("Zombie 1");
    zombie1->annonce();
    Zombie* zombie2 = newZombie("Zombie 2");
    zombie2->annonce();
    delete zombie1;
    delete zombie2;
    std::cout << std::endl;
    randomChump("Bob");
}