/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:21:15 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/24 10:06:04 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog ::Dog(void)
{
    Animal::setType("Dog");
    _brain = new Brain();
    LOG("Dog default constructor called");
}

Dog ::Dog(const Dog &copy) : Animal(copy)
{
    *this = copy;
    LOG("Dog copy constructor called");
}

Dog ::~Dog(void)
{
    delete _brain;
    LOG("Dog default destructor called");
}

// OPERATOR OVERLOAD
Dog &Dog ::operator=(const Dog &rhs)
{
    if (this != &rhs)
    {
        Animal::operator=(rhs);
        if (_brain != nullptr)
            delete _brain;
        _brain = new Brain(*(rhs._brain));
    }
    return (*this);
}

// METHODS
void Dog ::makeSound(void) const { std::cout << "WOAF" << std::endl; }

Brain *Dog ::getBrain(void) const { return (_brain); }