/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:07:18 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/21 15:39:16 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat :: Cat( void )
{
	Animal::setType("Cat");
	_brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat :: Cat( const Cat &copy ) : Animal(copy)
{
	*this = copy;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat :: ~Cat( void )
{
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

//OPERATOR OVERLOAD
Cat &Cat :: operator=( const Cat &rhs )
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		if (_brain != nullptr)
			delete _brain;
		_brain = new Brain(rhs.getBrain());
	}
	return (*this);
}

//METHOD
void	Cat :: makeSound( void ) const
{
	std::cout << "MIAOW" << std::endl;
}

Brain	&Cat :: getBrain( void )	const
{
	return (*_brain);
}