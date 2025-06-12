/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:10:45 by licohen           #+#    #+#             */
/*   Updated: 2025/06/12 13:40:49 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

std::string Replace::replaceAll(const std::string& content, const std::string& s1, const std::string& s2)
{
    if (s1.empty())
        return content;
    std::string result;
    size_t pos = 0;
    size_t prev = 0;
    while ((pos = content.find(s1, prev)) != std::string::npos)
    {
        result += content.substr(prev, pos - prev);
        result += s2;
        prev = pos + s1.length();
    }
    result += content.substr(prev);
    
    return result;
}

bool Replace::process(const std::string& filename, const std::string& s1, const std::string& s2)
{
	std::ifstream inputFile(filename.c_str());
	if (!inputFile)
	{
		std::cerr << "Error: Unable to open file: " << filename << std::endl;
		return false;
	}
	std::ofstream outputFile((filename + ".replace").c_str());
	if (!outputFile)
	{
		std::cerr << "Error: Unable to create output file: " << filename << std::endl;
		return false;
	}
	std::string line;
	while (std::getline(inputFile, line))
		outputFile << replaceAll(line, s1, s2) << std::endl;
	return true;
}