/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:44:15 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/22 15:37:58 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"

Ice :: Ice( void )
{
	_type = "ice";
	LOG("Ice constructor called");
}

Ice :: Ice( const Ice &copy )
{
	*this = copy;
	LOG("Ice copy constructor called");
}

Ice :: ~Ice( void )
{
	LOG("Ice destructor called");
}

//OVERLOADS
Ice &Ice :: operator=(const Ice &rhs)
{
	if (this != &rhs)
		_type = rhs.getType();
	return (*this);
}

//METHODS
void	Ice :: use( ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" 
	<< std::endl;
}

//Should I return the abstract base class?
AMateria	*Ice :: clone( void )	const
{
	return (new Ice(*this));
}