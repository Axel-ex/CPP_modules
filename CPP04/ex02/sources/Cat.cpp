/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:07:18 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/24 10:34:45 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat :: Cat( void )
{
	AAnimal::setType("Cat");
	_brain = new Brain();
	LOG("Cat default constructor called");
}

Cat :: Cat( const Cat &copy ) : AAnimal(copy)
{
	*this = copy;
	LOG("Cat copy constructor called");
}

Cat :: ~Cat( void )
{
	delete _brain;
	LOG("Cat destructor called");
}

//OPERATOR OVERLOAD
Cat &Cat :: operator=( const Cat &rhs )
{
	if (this != &rhs)
	{
		AAnimal::operator=(rhs);
		if (_brain != nullptr)
			delete _brain;
		_brain = new Brain(*(rhs._brain));
	}
	return (*this);
}

std::ostream	&operator<<( std::ostream &ofs, const Cat &rhs )
{
	ofs << "CAT" << std::endl;
	ofs << "type: " << rhs.getType() << std::endl;
	ofs << "ideas: " << std::endl;
	rhs.getBrain()->print();
	return (ofs);
}

//METHOD
void	Cat :: makeSound( void )	const
{
	std::cout << "MIAOW" << std::endl;
}

Brain	*Cat :: getBrain( void )	const
{
	return (_brain);
}