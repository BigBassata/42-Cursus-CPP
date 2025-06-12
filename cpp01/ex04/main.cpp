/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:32:02 by licohen           #+#    #+#             */
/*   Updated: 2025/06/12 15:11:22 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

int main(int argc, char* argv[])
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
		std::cerr << "Error: The string s2 replace (s1) cannot be empty." << std::endl;
		return 1;
	}

	if (!Replace::process(filename, s1, s2))
	{
		std::cerr << "Error: Failed to process file." << std::endl;
		return 1;
	}
	std::cout << "Output saved to " << filename << ".replace" << std::endl;
	return 0;
}