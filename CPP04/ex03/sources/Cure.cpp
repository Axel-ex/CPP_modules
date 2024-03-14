/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:28:45 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/26 11:55:49 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"

Cure ::Cure(void)
{
    LOG("Cure constructor called");
    _type = "cure";
}

Cure ::Cure(const Cure &copy) : AMateria(copy) { *this = copy; }

Cure ::~Cure(void) { LOG("Cure destructor called"); }

Cure &Cure ::operator=(const Cure &rhs)
{
    if (this != &rhs)
        AMateria::operator=(rhs);
    return (*this);
}

void Cure ::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria *Cure ::clone(void) const { return (new Cure(*this)); }