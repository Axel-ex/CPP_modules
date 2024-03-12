/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:24:06 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/28 10:12:20 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.hpp"

Base	*generate( void )
{
	switch (rand() % 3)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			return (NULL);
	}
}

void	identify( Base *p )
{
	if (dynamic_cast<A *>(p))
		std::cout << "it is a pointer on A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "it is a pointer on B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "it is a pointer on C" << std::endl;
	else
		std::cout << "UNKNOWN" << std::endl;
}

void	identify( Base &p )
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "it is a reference on A" << std::endl;
	}
	catch (std::bad_cast &e)
	{}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "it is a reference on B" << std::endl;
	}
	catch (std::bad_cast &e)
	{}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "it is a reference on C" << std::endl;
	}
	catch (std::bad_cast &e)
	{}
}