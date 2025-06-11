/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:03:19 by licohen           #+#    #+#             */
/*   Updated: 2025/05/22 12:34:35 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

/* le constructeur initialise les attributs a leur valeur par defaut
Quand un nouvel objet PhoneBook est cree : 
- contactCount est mis a 0, 
- oldestIndex est mis a 0 (le premier contact sera remplace en premier si le carnet est plein) */
PhoneBook::PhoneBook()
{
    this->contactCount = 0;
    this->oldestIndex = 0;
}

int PhoneBook::getContactCount()
{
    return this->contactCount;
}

/* Le destructeur est vide car il; n y a pas d operations speciale a effectuer lors de la destruction
(comme liberer la memoire) */
PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(Contact contact)
{
    if (this->contactCount < 8)
    {
        this->contacts[this->contactCount] = contact;
        this->contactCount++;
    }
    else 
    {
        this->contacts[this->oldestIndex] = contact;
        this->oldestIndex = (this->oldestIndex + 1) % 8;
    }
}


std::string truncate(std::string str, size_t width)
{
    if (str.length() > width)
        return str.substr(0, width -1) + ".";
    return str;
}

/* Affiche un tableau formate avec tous les contacts, cette fonction cree d abord un en tete avec 
les noms des colonnes, puis elle parcourt tous les contacts enregistres avec une boucle for, pour chaque contact
elle affiche sont index et ses informations prinicipales. std::setw(10) definit la largeur de chaque colonne 
a 10 caracteres. la fonction truncate assure que les textes trop longs sont coupes proporement. */
void PhoneBook::displayContacts()
{
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "|"
              << std::setw(10) << "Phone Number" << "|" 
              << std::setw(10) << "Darkest Secret" << std::endl;

    for (int i = 0; i < this->contactCount; i++)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncate(this->contacts[i].getFirstName(), 10) << "|"
                  << std::setw(10) << truncate(this->contacts[i].getLastName(), 10) << "|"
                  << std::setw(10) << truncate(this->contacts[i].getNickname(), 10) << "|"
                  << std::setw(10) << truncate(this->contacts[i].getPhoneNumber(), 10) << "|"
                  << std::setw(10) << truncate(this->contacts[i].getDarkestSecret(), 10) << std::endl;

    }
}

/*cette methode affiche les details d un contact specifique, elle verifie d abord si l'index est valide (entre 0 et contactCount -1)
Si oui, elle affiche les infos du contact demande, sinon elle affiche un message d erreur indiquant la plage d indices valides.*/
void PhoneBook::displayContact(int index)
{
    if (index >= 0 && index < this->contactCount)
    {
        std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "|"
              << std::setw(10) << "Phone Number" << std::endl;
        std::cout << std::setw(10) << index << "|"
                  << std::setw(10) << this->contacts[index].getFirstName() << "|"
                  << std::setw(10) << this->contacts[index].getLastName() << "|"
                  << std::setw(10) << this->contacts[index].getNickname() << "|"
                  << std::setw(10) << this->contacts[index].getPhoneNumber() << "|"
                  << std::setw(10) << this->contacts[index].getDarkestSecret() << std::endl;
    }
    else
    {
        std::cout << "Error: Invalid index. Please enter a number between 0 and " << this->contactCount - 1 << "." << std::endl;
    }
}

