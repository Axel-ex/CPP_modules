/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:13:55 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/22 15:33:18 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

// CONSTRUCTOR
AMateria ::AMateria(void) { LOG("AMateria default constructor called"); }

AMateria ::AMateria(const std::string &type) : _type(type)
{
    LOG("AMateria copy constructor called");
}

AMateria ::~AMateria(void) { LOG("AMateria destructor called"); }

// MEMBER FCTS
const std::string &AMateria ::getType(void) const { return (_type); }

void AMateria ::use(ICharacter &target) { (void)target; }

bool AMateria ::getIsTaken(void) const { return (_is_taken); }

void AMateria ::setIsTaken(bool set_value) { _is_taken = set_value; }