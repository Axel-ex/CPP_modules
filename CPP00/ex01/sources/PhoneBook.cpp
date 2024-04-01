/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:00:23 by achabrer          #+#    #+#             */
/*   Updated: 2024/04/01 10:32:06 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"
#include <iostream>
#include <limits>

PhoneBook::PhoneBook(void) { this->_id = -1; }

PhoneBook::~PhoneBook(void) {}

void PhoneBook::add(void)
{
    const std::string prompts[] = {
        "Enter a name", "Enter a last name", "Enter a nickname",
        "Enter a telephone number", "Enter his/her darkest secret"};
    std::string attributes[5];

    this->_id = (this->_id == MAX_CONTACTS - 1) ? MAX_CONTACTS - 2 : this->_id;
    for (unsigned int j = 0; j < sizeof(prompts) / sizeof(prompts[0]); ++j)
    {
        std::cout << CLEAR;
        std::cout << YELLOW << ADD_TITLE << RESET << std::endl;
        std::cout << prompts[j] << std::endl;
        std::getline(std::cin, attributes[j], '\n');
        if (attributes[j].empty())
        {
            PhoneBook::printError("a field can not be empty");
            std::cout << "\npress ENTER to continue" << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }
    }
    Contact newContact = Contact(attributes[0], attributes[1], attributes[2],
                                 attributes[3], attributes[4]);
    this->_contacts[++_id] = newContact;
    std::cout << std::endl
              << attributes[0] << " added to the book, press ENTER to continue"
              << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void PhoneBook::search(void)
{
    int id;

    std::cout << CLEAR;
    std::cout << YELLOW << SEARCH_TITLE << RESET << std::endl;
    this->_display();
    std::cout << "Enter the index of the contact you want to look up"
              << std::endl;

    while (true)
    {
        std::cin >> id;
        if (std::cin.fail())
        {
            if (std::cin.eof())
				break;
            PhoneBook::printError("Enter an integer value");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (id < 0 || id > MAX_CONTACTS - 1)
            PhoneBook::printError("Enter a valid index");
        else
        {
            this->_contacts[id].display();
            std::cout << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
}

void PhoneBook::_display(void) const
{
    std::string field;

    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    for (int i = 0; i < MAX_CONTACTS; i++)
    {
        std::cout << "|" << std::setw(10) << i << "|";
        field = this->_contacts[i].getFirstName();
        std::cout << std::setw(10) << Contact::formatField(field) << "|";
        field = this->_contacts[i].getLastName();
        std::cout << std::setw(10) << Contact::formatField(field) << "|";
        field = this->_contacts[i].getNickname();
        std::cout << std::setw(10) << Contact::formatField(field) << "|";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void PhoneBook::printMenu(void)
{
    std::cout << CLEAR;
    std::cout << YELLOW << TITLE << RESET << std::endl;
    std::cout << "Usage:";
    std::cout << "\t- ADD" << std::endl;
    std::cout << "\t- SEARCH" << std::endl;
    std::cout << "\t- EXIT" << std::endl;
    std::cout << std::endl;
}

void PhoneBook::printError(std::string msg)
{
    std::cout << RED << "error: " << RESET << msg << std::endl;
}
