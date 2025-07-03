/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:47:37 by licohen           #+#    #+#             */
/*   Updated: 2025/06/27 23:43:45 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <sstream>

static bool isValidName(const std::string& str)
{
	if (str.empty())
		return false;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isalpha(str[i]) && str[i] != ' ' && str[i] != '-' && str[i] != '\'')
			return false;
	}
	return true;
}

static bool isValidNumber(const std::string& str)
{
	if (str.empty())
		return false;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]) && str[i] != ' ' && str[i] != '+' && 
			str[i] != '-' && str[i] != '(' && str[i] != ')')
			return false;
	}
	return true;
}

static bool isValidSecret(const std::string& str)
{
	if (str.empty())
		return false;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ' && str[i] != '\t')
			return true;
	}
	return false;
}

static std::string trim(const std::string& str)
{
	size_t start = 0;
	size_t end = str.length();

	while (start < end && (str[start] == ' ' || str[start] == '\t'))
		start++;
	while (end > start && (str[end - 1] == ' ' || str[end - 1] == '\t')) 
		end--;
	return str.substr(start, end - start);
}

static std::string getValidInput(const std::string& prompt, const std::string& type)
{
	std::string input;
	
	while (true)
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		input = trim(input);
		
		if (input.empty()) 
		{
			std::cout << "Error: Input cannot be empty. Please try again." << std::endl;
			continue;
		}
		if (type == "name")
		{
			if (isValidName(input))
				return input;
			else 
				std::cout << "Error: Name should only contain letters, spaces, hyphens and apostrophes. Please try again." << std::endl;
		}
		else if (type == "phone")
		{
			if (isValidNumber(input))
				return input;
			else 
				std::cout << "Error: Phone number should only contain digits, spaces, +, -, (, ). Please try again." << std::endl;
		}
		else if (type == "secret")
		{
			if (isValidSecret(input))
				return input;
			else 
				std::cout << "Error: Secret cannot be empty or contain only spaces. Please try again." << std::endl;
		}
	}
}

int main(int argc, char **argv)
{
	PhoneBook phoneBook;
	std::string command;
	
	if (argc > 1)
	{
		std::cout << "Usage: " << argv[0] << std::endl;
		return 1;
	}
	
	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		
		if (std::cin.eof())
		{
			std::cout << "\n........ Program Interrupted .........." << std::endl;
			break;
		}
		if (command == "ADD")
		{
			Contact contact;
			contact.setFirstName(getValidInput("Enter first name: ", "name"));
			contact.setLastName(getValidInput("Enter last name: ", "name"));
			contact.setNickname(getValidInput("Enter nickname: ", "name"));
			contact.setPhoneNumber(getValidInput("Enter phone number: ", "phone"));
			contact.setDarkestSecret(getValidInput("Enter darkest secret: ", "secret"));
			phoneBook.addContact(contact);
			std::cout << "Contact added successfully!" << std::endl;
		}
		else if (command == "SEARCH")
		{
			if (phoneBook.getContactCount() == 0)
			{
				std::cout << "No contacts available." << std::endl;
				continue;
			}
			phoneBook.displayContacts();
			std::cout << "Enter index of contact to display: ";
			std::getline(std::cin, command);
			
			int index;
			std::istringstream iss(command);
			if (!(iss >> index))
			{
				std::cout << "Error: Invalid input. Please enter a number." << std::endl;
				continue;
			}
			if (index < 0 || index >= phoneBook.getContactCount())
			{
				std::cout << "Error: Index out of range. Please enter a number between 0 and "
						<< phoneBook.getContactCount() - 1 << "." << std::endl;
				continue;
			}
			phoneBook.displayContact(index);
		}
		else if (command == "EXIT")
		{
			break;
		}
		else
		{
			std::cout << "Invalid command. Please use ADD, SEARCH, or EXIT." << std::endl;
		}
	}
	return 0;
}