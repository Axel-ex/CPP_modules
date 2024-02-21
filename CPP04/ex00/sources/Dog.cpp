/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:21:15 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/21 10:07:14 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog :: Dog( void )
{
	Animal::setType("Dog");
	std::cout << "Dog default constructor called" << std::endl;
}

Dog :: Dog( const Dog &copy ) : Animal(copy)
{
	*this = copy;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog :: ~Dog( void )
{
	std::cout << "Dog default destructor called" << std::endl;
}

//OPERATOR OVERLOAD
Dog &Dog :: operator=( const Dog &rhs )
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
	}
	return (*this);
}

//METHODS
void	Dog :: makeSound( void )	const
{
	std::cout << "WOAF" << std::endl;
}