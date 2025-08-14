/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:25:14 by licohen           #+#    #+#             */
/*   Updated: 2025/07/03 16:56:10 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main()
{
    Harl harl;
    std::string level;
    while (1)
    {
        std::cout << "Enter a level (DEBUG, INFO, WARNING, ERROR) or Q to quit: ";
        if (!(std::cin >> level))
        {
            std::cout << "\nEOF detected" << std::endl;
            break;
        }
        if (level != "DEBUG" && level != "INFO" && level != "WARNING" && 
            level != "ERROR" && level != "Q")
        {
            std::cout << "Invalid input" << std::endl;
            continue;
        }
        if (level == "Q")
            break;
        harl.complain(level);
    }
    std::cout << "Exiting..." << std::endl;
    return (0);
}