/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:44:07 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/24 10:51:25 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"

// CONSTRUCTORS
AAnimal ::AAnimal(void) : _type("Animal")
{
    LOG("Animal default constructor called");
}

AAnimal ::AAnimal(const AAnimal &copy)
{
    *this = copy;
    LOG("Animal copy constructor called");
}

AAnimal ::~AAnimal(void) { LOG("Animal default destructor called"); }

// OPERATOR OVERLOAD
AAnimal &AAnimal ::operator=(const AAnimal &rhs)
{
    if (this != &rhs)
        _type = rhs.getType();
    return (*this);
}

// GETTERS AND SETTERS
std::string AAnimal ::getType(void) const { return (_type); }

void AAnimal ::setType(const std::string &type) { _type = type; }
