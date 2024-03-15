/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:01:27 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/20 15:05:46 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:07:18 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/20 14:48:16 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat ::WrongCat(void)
{
    WrongAnimal::setType("WrongCat");
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat ::WrongCat(const WrongCat& copy) : WrongAnimal(copy)
{
    *this = copy;
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat ::~WrongCat(void)
{
    std::cout << "WrongCat destructor called" << std::endl;
}

// OPERATOR OVERLOAD
WrongCat& WrongCat ::operator=(const WrongCat& rhs)
{
    if (this != &rhs)
        WrongAnimal::operator=(rhs);
    return (*this);
}

// METHOD
void WrongCat ::makeSound(void) const { std::cout << "MIAOW" << std::endl; }