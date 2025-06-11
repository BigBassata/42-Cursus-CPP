/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:32:02 by licohen           #+#    #+#             */
/*   Updated: 2025/06/11 16:48:10 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <string_to_replace> <replacement_string>" << std::endl;
		return 1;
	}

	const std::string filename = argv[1];
	const std::string from = argv[2];
	const std::string to = argv[3];

	if (from.empty()) {
		std::cerr << "Error: The string to replace (from) cannot be empty." << std::endl;
		return 1;
	}

	if (!Replace::process(filename, from, to))
	{
		std::cerr << "Error: Failed to process file." << std::endl;
		return 1;
	}
	std::cout << "Replacement completed. Output saved to " << filename << ".replace" << std::endl;
	return 0;
}