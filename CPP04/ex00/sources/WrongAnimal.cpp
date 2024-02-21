/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:44:07 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/20 15:03:34 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

//CONSTRUCTORS
WrongAnimal :: WrongAnimal( void ) : _type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal :: WrongAnimal( const WrongAnimal &copy )
{
	*this = copy;	
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal :: ~WrongAnimal( void )
{
	std::cout << "WrongAnimal default destructor called" << std::endl;
}

//OPERATOR OVERLOAD
WrongAnimal &WrongAnimal :: operator=( const WrongAnimal &rhs)
{
	if (this != &rhs)
		_type = rhs.getType();
	return (*this);
}

//GETTERS AND SETTERS
std::string	WrongAnimal :: getType( void )	const
{
	return (_type);
}

void	WrongAnimal :: setType( const std::string &type)
{
	_type = type;
}

//METHODS
void	WrongAnimal :: makeSound( void )	const
{
	std::cout << "AAAAARRRGH" << std::endl;
}