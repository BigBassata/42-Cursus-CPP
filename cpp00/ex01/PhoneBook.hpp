/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:12:04 by licohen           #+#    #+#             */
/*   Updated: 2025/06/28 17:32:29 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook
{
private:
	Contact _contacts[8];
	int _contactCount;
	int _oldestIndex;

public:
	PhoneBook();
	~PhoneBook();

	void addContact(Contact contact);
	void displayContacts();
	void displayContact(int index);
	int getContactCount();
	
};


#endif