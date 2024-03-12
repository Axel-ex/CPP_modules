/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:51:10 by achabrer          #+#    #+#             */
/*   Updated: 2024/03/01 11:33:30 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<typename T, typename C>
MutantStack<T, C> :: MutantStack( void )
{}

template<typename T, typename C>
MutantStack<T, C> :: MutantStack( const MutantStack<T, C> &src ) : std::stack<T, C>(src)
{
	*this = src;
}

template<typename T, typename C>
MutantStack<T, C> :: ~MutantStack( void )
{}

//OPERATOR
template<typename T, typename C>
MutantStack<T, C>	&MutantStack<T, C> :: operator=( const MutantStack &rhs )
{
	if (this != &rhs)
		std::stack<T, C>::operator=(this, rhs);
	return (*this);
}

//ITERATORS
template<typename T, typename C>
typename C::iterator	MutantStack<T, C> :: begin( void )
{
	return (this->c.begin());
}

template<typename T, typename C>
typename C::iterator	MutantStack<T, C> :: end( void )
{
	return (this->c.end());
}

template<typename T, typename C>
typename C::const_iterator	MutantStack<T, C> :: cbegin( void ) const
{
	return (this->c.cbegin());
}

template<typename T, typename C>
typename C::const_iterator	MutantStack<T, C> :: cend( void )	const
{
	return (this->c.cend());
}