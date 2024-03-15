/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:44:07 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/23 22:28:47 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

// CONSTRUCTORS
Animal ::Animal(void) : _type("animal")
{
    LOG("Animal default constructor called");
}

Animal ::Animal(const Animal& copy)
{
    *this = copy;
    LOG("Animal copy constructor called")
}

Animal ::~Animal(void){LOG("Animal default destructor called")}

// OPERATOR OVERLOAD
Animal& Animal ::operator=(const Animal & rhs)
{
    if (this != &rhs)
        _type = rhs.getType();
    return (*this);
}

// GETTERS AND SETTERS
std::string Animal ::getType(void) const { return (_type); }

void Animal ::setType(const std::string& type) { _type = type; }

// METHODS
void Animal ::makeSound(void) const { return; }