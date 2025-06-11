/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:12:04 by licohen           #+#    #+#             */
/*   Updated: 2025/05/20 15:07:15 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip> // Pour std::setw
#include <sstream>
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8]; // Tableau de 8 contacts
    int contactCount;    // Nombre de contacts actuellement enregistrés
    int oldestIndex;     // Indice du plus ancien contact

public:
    PhoneBook();
    ~PhoneBook();

    void addContact(Contact contact);
    void displayContacts();
    void displayContact(int index);
    int getContactCount();
};

#endif