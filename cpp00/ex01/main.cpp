/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:47:37 by licohen           #+#    #+#             */
/*   Updated: 2025/05/22 12:56:50 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <sstream>

bool isValidName(const std::string& str)
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isalpha(str[i]) && str[i] != ' ' && str[i] != '-' & str[i] != '\'')
            return false;
    }
    return true;
}

bool isValidNumber(const std::string& str)
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

bool isValidSecret(const std::string& str) {
    if (str.empty()) {
        return false;
    }
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ' && str[i] != '\t')
            return true;
    }
    return false;
}

std::string trim(const std::string& str)
{
    size_t start = 0;
    size_t end = str.length();

    while (start < end && (str[start] == ' ' || str[start] == '\t'))
        start++;
    while (end > start && (str[end - 1] == ' ' || str[end - 1] == '\t')) 
        end--;
    return str.substr(start, end - start);
}

/*Cette fonction est concu pour afficher un message demandant une saisie a l utilisateur, 
lire sa saisie, verifier qu elle n est pas vide, si elle l'est, afficher une erreur et redemander, 
sinon retourne la saisie.
prompt est une reference a la chaine de caractere passee a la fonction, le const garantit 
que getvalid input ne paeut pas modifier cette chiane, comme c est une reference aucune copie 
n est cree*/
std::string getValidInput(const std::string& prompt, const std::string& type) {
    std::string input;
    while (true) {
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
        if (type == "phone")
        {
            if (isValidNumber(input))
                return input;
            else 
                std::cout << "Error: Phone number should only contain digits, spaces, +, -. Please try again." << std::endl;
        }
        if (type == "secret")
        {
            if (isValidSecret(input))
                return input;
            else 
                std::cout << "Error: Secret should connot be empty or contain only spaces. Please try again." << std::endl;
        }
        
    }
}

int main(int argc, char **argv)
{
    /*on cree un objet nomme PhoneBook*/
    PhoneBook phoneBook;
    /*On declare une variable command pour stocket les commandes de l'utilisateur*/
    std::string command;
    /*On verifie si des arguments ont ete passes au prog*/
    if (argc > 1)
    {
        std::cout << "Usage: " << argv[0] << std::endl;
    }
    /*cette boucle while cree un prog qui tourne indefiniment jusqu'a ce qu on lui demande explicitment 
    de s arreter (avec la commande EXIT). A chaque iteration, le prog demande a l utilisateur d entrer une commande 
    et l enregistre dans la variable command*/
    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        
        /*traitement de la commande ADD : si l utilisateur entre la commande ADD, le prog
        cree un nouvel objet Contact, utilise la fonciton getvalidInput pour demander et recueuillir chaque info, 
        definit chaque attribut du contact avec les setters appropries, ajoute le contatc complet au carnet telephonique 
        avec phoneBook.addContact(contact)*/
        if (command == "ADD")
        {
            Contact contact;
            contact.setFirstName(getValidInput("Enter first name: ", "name"));
            contact.setLastName(getValidInput("Enter last name: ", "name"));
            contact.setNickname(getValidInput("Enter nickname: ", "name"));
            contact.setPhoneNumber(getValidInput("Enter phone number: ", "phone"));
            contact.setDarkestSecret(getValidInput("Enter darkest secret: ", "secret"));
            phoneBook.addContact(contact);
        }
        /*traitement de la commande SEARCH : si l utilisateur entre l cmd SEARCH, le prog affiche un tableau de tous les contacts
        existants avec phoneBook.displayContacts(), demande a l utilisateur d entrer l index du contact a afficher en detail, tente de convertir 
        la saisie en nombre avec std::istringstream, si echoue affiche une erreur et revient au debut de la boucle, puis verifie si l index est dans la plage valide, 
        affiche les details du contact demande avec phoneBook.displayContact(index)*/
        else if (command == "SEARCH")
        {
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
            std::cout << "INVALID COMMAND"<< std::endl;
        }
    }
    return 0;
}