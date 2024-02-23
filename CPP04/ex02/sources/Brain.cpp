/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:28:59 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/21 11:17:34 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain :: Brain( void )
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain :: Brain( const Brain &copy )
{
	*this = copy;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain :: ~Brain( void )
{
	std::cout << "Brain destructor called" << std::endl;
}

//OPERATOR OVERLOAD
Brain &Brain :: operator=( const Brain &rhs )
{
	if (this != &rhs)
	{
		for (int i = 0; i < NB_IDEAS; i++)
			_ideas[i] = rhs.getIdea(i);
	}
	return (*this);
}

//MEMBER FUNCTIONS
std::string Brain :: getIdea( int index ) const
{
	if (index > NB_IDEAS)
		throw std::runtime_error("Ideas index out of range");
	return (_ideas[index]);
}

void	Brain :: setIdea( const std::string &idea, int index )
{
	if (index > NB_IDEAS)
		throw std::runtime_error("Ideas index out of range");
	_ideas[index] = idea;
}