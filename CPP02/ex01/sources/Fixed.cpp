/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:15:34 by achabrer          #+#    #+#             */
/*   Updated: 2024/03/14 15:19:15 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

const int Fixed::_bits = 8;

Fixed :: Fixed( void ) : _raw_bits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed :: Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_raw_bits = value << Fixed::_bits;
}

//all float can not be converted in int with the 8 bit shift =
// tradeof accurracy / precision
Fixed :: Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_raw_bits = value * (1 << Fixed::_bits);
}

//Copy constructor
Fixed :: Fixed( const Fixed &to_copy) : _raw_bits(to_copy._raw_bits)
{
	std::cout << "copy constructor called" << std::endl;
}

Fixed :: ~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed& to_copy)
{
	std::cout << "copy assignement operator called" << std::endl;
	if (this != &to_copy)
		this->_raw_bits = to_copy._raw_bits;
	return (*this);
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_raw_bits);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_raw_bits = raw;
}

float Fixed :: toFloat(void) const
{
	return ((float)this->_raw_bits / (float)(1 << Fixed::_bits));
}

int Fixed :: toInt(void) const
{
	return (this->_raw_bits >> Fixed::_bits);
}
//insertion overload operator. binary op should be nonmember.
// return the output stream for chaining purpose
std::ostream &operator<<(std::ostream &ofs, const Fixed &fixed)
{
	ofs << fixed.toFloat();
	return (ofs);
}
