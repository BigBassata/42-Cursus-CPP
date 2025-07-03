/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:03:19 by licohen           #+#    #+#             */
/*   Updated: 2025/06/26 16:07:32 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_contactCount = 0;
	this->_oldestIndex = 0;
}

PhoneBook::~PhoneBook()
{
}

int PhoneBook::getContactCount()
{
	return this->_contactCount;
}

void PhoneBook::addContact(Contact contact)
{
	if (this->_contactCount < 8)
	{
		this->_contacts[this->_contactCount] = contact;
		this->_contactCount++;
	}
	else
	{
		this->_contacts[this->_oldestIndex] = contact;
		this->_oldestIndex = (this->_oldestIndex + 1) % 8;
	}
}

static std::string truncate(std::string str, size_t width)
{
	if (str.length() > width)
		return str.substr(0, width - 1) + ".";
	return str;
}

void PhoneBook::displayContacts()
{
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < this->_contactCount; i++)
	{
		std::cout << std::setw(10) << i << "|"
				  << std::setw(10) << truncate(this->_contacts[i].getFirstName(), 10) << "|"
				  << std::setw(10) << truncate(this->_contacts[i].getLastName(), 10) << "|"
				  << std::setw(10) << truncate(this->_contacts[i].getNickname(), 10) << std::endl;
	}
}

void PhoneBook::displayContact(int index)
{
	if (index >= 0 && index < this->_contactCount)
	{
		std::cout << "First Name: " << this->_contacts[index].getFirstName() << std::endl;
		std::cout << "Last Name: " << this->_contacts[index].getLastName() << std::endl;
		std::cout << "Nickname: " << this->_contacts[index].getNickname() << std::endl;
		std::cout << "Phone Number: " << this->_contacts[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << this->_contacts[index].getDarkestSecret() << std::endl;
	}
	else
	{
		std::cout << "Error: Invalid index. Please enter a number between 0 and " 
				  << this->_contactCount - 1 << "." << std::endl;
	}
}