/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:15:34 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/15 15:58:32 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

const int Fixed::_bits = 8;

Fixed ::Fixed(void) : _val(0)
{
    std::cout << "Default constrcutor called" << std::endl;
}

// Copy constructor
Fixed ::Fixed(const Fixed& to_copy) : _val(to_copy._val)
{
    std::cout << "copy constructor called" << std::endl;
}

// Copy assignement operator overload
//  the = sign is beeing "overloaded"
Fixed& Fixed::operator=(const Fixed& to_copy)
{
    std::cout << "copy assignement operator called" << std::endl;
    if (this != &to_copy)
        this->_val = to_copy._val;
    return (*this);
}

Fixed ::~Fixed(void) { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_val);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_val = raw;
}