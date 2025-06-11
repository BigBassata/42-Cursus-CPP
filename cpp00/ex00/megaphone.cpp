/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:18:27 by licohen           #+#    #+#             */
/*   Updated: 2025/05/14 14:23:39 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

std::string to_upper(std::string str)
{
    std::string to_uppercase = str;
    
    for (size_t i = 0; i < to_uppercase.length(); i++)
    {
        to_uppercase[i] = std::toupper(str[i]);
    }
    return (to_uppercase);
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    else
    {
        std::string result = "";
        for (int i = 1; i < argc; i++)
        {
            result += to_upper(argv[i]);
        }
        std::cout << result << std::endl;
    }
    return (0);
}
