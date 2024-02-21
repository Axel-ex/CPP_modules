/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:15:34 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/16 13:59:04 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

const int Fixed::_bits = 8;

Fixed :: Fixed( void ) : _val(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed :: Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_val = value * (1 << Fixed::_bits);
}

//all float can not be converted in int with the 8 bit shift =
// tradeof accurracy / precision
Fixed :: Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_val = value * (1 << Fixed::_bits);
}

//Copy constructor
Fixed :: Fixed( const Fixed &to_copy) : _val(to_copy._val)
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
		this->_val = to_copy._val;
	return (*this);
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_val);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_val = raw;
}

float Fixed :: toFloat(void) const
{
	return ((float)this->_val / (float)(1 << Fixed::_bits));
}

int Fixed :: toInt(void) const
{
	return (this->_val >> Fixed::_bits);
}
//insertion overload operator. binary op should be nonmember.
// return the output stream for chaining purpose
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}