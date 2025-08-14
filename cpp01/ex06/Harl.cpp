/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:24:14 by licohen           #+#    #+#             */
/*   Updated: 2025/07/11 15:56:17 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug(void)
{
    std::cout << "DEBUG" << std::endl;
}

void Harl::info(void)
{
    std::cout << "INFO" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "WARNING" << std::endl;
}

void Harl::error(void)
{
    std::cout << "ERROR" << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*functions[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    
    int startIndex = -1;
    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            startIndex = i;
            break;
        }
    }
    switch (startIndex)
    {
        case 0: 
            (this->*functions[0])();
        case 1: 
            (this->*functions[1])();
        case 2: 
            (this->*functions[2])();
        case 3: 
            (this->*functions[3])();
            break;
        default:
            std::cout << "Probably complaining about insignificant problems " << std::endl;
            break;
    }
}
