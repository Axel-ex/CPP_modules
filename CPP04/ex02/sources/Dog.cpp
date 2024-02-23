/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:21:15 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/21 11:32:40 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog :: Dog( void )
{
	Animal::setType("Dog");
	_brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog :: Dog( const Dog &copy ) : Animal(copy)
{
	*this = copy;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog :: ~Dog( void )
{
	delete _brain;
	std::cout << "Dog default destructor called" << std::endl;
}

//OPERATOR OVERLOAD
Dog &Dog :: operator=( const Dog &rhs )
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		_brain = new Brain(rhs.getBrain());
	}
	return (*this);
}

//METHODS
void	Dog :: makeSound( void )	const
{
	std::cout << "WOAF" << std::endl;
}

Brain	&Dog :: getBrain( void )	const
{
	return (*_brain);
}