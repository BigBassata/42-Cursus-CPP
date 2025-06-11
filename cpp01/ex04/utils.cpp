/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:10:45 by licohen           #+#    #+#             */
/*   Updated: 2025/06/11 17:01:00 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

std::string Replace::replaceAll(const std::string& content, const std::string& from, const std::string& to)
{
    if (from.empty())
        return content;
    
    std::string result;
    size_t pos = 0;
    size_t prev = 0;

    while ((pos = content.find(from, prev)) != std::string::npos)
    {
        // Ajouter la partie avant l'occurrence trouvée
        result += content.substr(prev, pos - prev);
        
        // Ajouter la chaîne de remplacement
        result += to;
        
        // Avancer après la chaîne trouvée
        prev = pos + from.length();
    }

    // Ajouter la dernière partie après la dernière occurrence
    result += content.substr(prev);
    
    return result;
}

bool Replace::process(const std::string& filename, const std::string& from, const std::string& to)
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
		outputFile << replaceAll(line, from, to) << std::endl;
	return true;
}