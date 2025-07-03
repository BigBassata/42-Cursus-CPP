/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:11:15 by licohen           #+#    #+#             */
/*   Updated: 2025/06/30 15:40:25 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string brainMessage = "HI THIS IS BRAIN";
    std::string *stringPTR = &brainMessage;
    std::string &stringREF = brainMessage;
    
    std::cout << "Adress of the string: " << &brainMessage << std::endl;
    std::cout << "Adress of the string: " << stringPTR << std::endl;
    std::cout << "Adress of the string: " << &stringREF << std::endl;

    std::cout << "Value: " << brainMessage << std::endl;
    std::cout << "Value: " << *stringPTR << std::endl;
    std::cout << "Value: " << stringREF << std::endl; 

    return 0;
}

