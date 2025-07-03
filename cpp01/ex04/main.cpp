/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:20:23 by licohen           #+#    #+#             */
/*   Updated: 2025/07/02 15:19:49 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replaceAll(const std::string &content, const std::string& s1, const std::string& s2)
{
    std::string result;
    size_t pos = 0;        
    size_t found = 0;     
    
    if (content.empty() || s1.empty())
        return content;
    while ((found = content.find(s1, pos)) != std::string::npos)
    {
        result += content.substr(pos, found - pos);
        result += s2;
        pos = found + s1.length();
    }
    result += content.substr(pos);
    return result;
}

bool processFile(const std::string& filename, const std::string& s1, const std::string& s2)
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
        std::cerr << "Error: Unable to create output file: " << filename << ".replace" << std::endl;
        return false;
    }
    std::string line;
    while (std::getline(inputFile, line))
    {
        outputFile << replaceAll(line, s1, s2) << std::endl;
    }
    return true;
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    const std::string filename = argv[1];
    const std::string s1 = argv[2];
    const std::string s2 = argv[3];
    
    if (s1.empty())
    {
        std::cerr << "Error: The string s1 cannot be empty." << std::endl;
        return 1;
    }
    std::ifstream testFile(filename.c_str());
    if (!testFile.is_open())
    {
        std::cerr << "Error: Cannot open file '" << filename << "'" << std::endl;
        return 1;    
    }
    testFile.close();
    if (!processFile(filename, s1, s2))
    {
        std::cout << "Erreur lors du traitement du fichier" << std::endl;
        return 1;
    }
    return 0;
}
    