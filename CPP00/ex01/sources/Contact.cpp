/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:46:21 by achabrer          #+#    #+#             */
/*   Updated: 2024/03/14 11:22:39 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

// default constructor
Contact::Contact(void)
    : _firstName(""), _lastName(""), _nickname(""), _phoneNumber(""),
      _darkestSecret("")
{
}

// Initialization list
Contact::Contact(std::string fn, std::string ln, std::string nn, std::string pn,
                 std::string ds)
    : _firstName(fn), _lastName(ln), _nickname(nn), _phoneNumber(pn),
      _darkestSecret(ds)
{
}

Contact::~Contact(void) {}

void Contact::display(void) const
{
    std::cout << CLEAR;
    std::cout << std::endl;
    std::cout << "First name:\t \"" << this->_firstName << "\"" << std::endl;
    std::cout << "Last name:\t \"" << this->_lastName << "\"" << std::endl;
    std::cout << "Nickname:\t \"" << this->_nickname << "\"" << std::endl;
    std::cout << "Phone Number:\t \"" << this->_phoneNumber << "\""
              << std::endl;
    std::cout << "Darkest Secret:\t \"" << this->_darkestSecret << "\""
              << std::endl;
    std::cout << "\nPress ENTER to go back." << std::endl;
    std::cin.ignore();
}

std::string Contact::formatField(std::string msg)
{
    if (msg.length() > 10)
        return (msg.substr(0, 9) + ".");
    return (msg);
}

std::string Contact::getFirstName(void) const { return (this->_firstName); }

std::string Contact::getLastName(void) const { return (this->_lastName); }

std::string Contact::getNickname(void) const { return (this->_nickname); }
