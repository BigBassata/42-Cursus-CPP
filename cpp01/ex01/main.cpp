/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:22:54 by licohen           #+#    #+#             */
/*   Updated: 2025/06/28 19:06:20 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <number_of_zombies> <zombies_name>"
                  << std::endl;
        return 1;
    }
    int nb_zombie = std::atoi(argv[1]);
    if (nb_zombie <= 0)
    {
        std::cerr << "Error: Number of zombies must be > 0" << std::endl;
        return 1;
    }
    Zombie* horde = zombieHorde(nb_zombie, argv[2]);
    for (int i = 0; i < nb_zombie; i++)
        horde[i].announce();
    delete[] horde;
    return 0;
}