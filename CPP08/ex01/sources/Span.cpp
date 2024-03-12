/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:52:15 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/29 15:38:25 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

Span :: Span ( void ) : _N(0)
{}

Span :: Span( unsigned int N ) : _N(N)
{}

Span :: Span( const Span &src )
{
	*this = src;
}

Span :: ~Span( void )
{}

//OPERATOR OVERLOAD
Span	&Span :: operator=( const Span &rhs )
{
	if (this != &rhs)
	{
		_array = rhs._array;
		_N = rhs._N;
	}
	return (*this);
}

std::ostream &operator<<( std::ostream &ofs, const Span &rhs )
{
	for (int i = 0; i < rhs.getSize(); i++)
	{
		std::cout << rhs.getElement(i);
		if (i + 1 != rhs.getSize())
			std::cout << ", ";
	}
	return (ofs);
}

//GETTERS / SETTERS
void	Span :: setMax( unsigned int max)
{
	_N = max; 
}

int		Span :: getElement( unsigned int idx )	const
{
	if (idx > _array.size())
		throw std::out_of_range("index out of range");
	return (_array[idx]);
}

int		Span :: getSize( void )	const
{
	return (_array.size());
}

int		Span :: min( void )		const
{
	return (*(std::min_element(_array.begin(), _array.end())));
}

int		Span :: max( void )		const
{
	return (*(std::max_element(_array.begin(), _array.end())));	
}

//MEMBER FCTS
void	Span :: addNumber( int to_add )
{
	if (_array.size() == _N)
		throw Span::FullSpanException();
	_array.push_back(to_add);
}

int		Span :: shortestSpan( void )	const
{
	int	distance = std::numeric_limits<int>::max();
	std::vector<int>::const_iterator	it;
	std::vector<int>	sorted = _array;

	if (_array.size() < 2)
		throw Span::NoSpanException();

	std::sort(sorted.begin(), sorted.end());
	for (it = sorted.cbegin(); it != sorted.cend() - 1; it++)
		if ((*(it + 1) - *it) < distance)
			distance = *(it + 1) - *it;

	return (distance);
}

int		Span :: longestSpan( void )	const
{
	if (_array.size() < 2)
		throw Span::NoSpanException();
	
	return (this->max() - this->min());	
}

static	int	generateRandom( void )
{
	return (std::rand() % 100000);
}

void	Span :: fill( void )
{
	_array.resize(_N);
	std::generate(_array.begin(), _array.end(), generateRandom);
}

//EXCEPTIONS
const char	*Span :: NoSpanException :: what ( void ) const throw()
{
	return ("No span can be calculated on an object of less than 2 elements");
}

const char	*Span :: FullSpanException :: what ( void ) const throw()
{
	return ("No span can be calculated on an object of less than 2 elements");
}