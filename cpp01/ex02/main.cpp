/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:43:18 by licohen           #+#    #+#             */
/*   Updated: 2025/05/28 15:09:11 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() 
{
    std::string brainMessage = "HI THIS IS BRAIN";
    std::string *stringPTR = &brainMessage;
    std::string &stringREF= brainMessage;

    std::cout << "Adress of string: " << &brainMessage << std::endl;
    std::cout << "Adress of stringPTR: " << stringPTR << std::endl;
    std::cout << "Adress of stringREF " << &stringREF << std::endl;
    
    std::cout << "Value of string: " << brainMessage << std::endl;
    std::cout << "Value of stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value of stringREF: " << stringREF << std::endl;

    return 0;
}