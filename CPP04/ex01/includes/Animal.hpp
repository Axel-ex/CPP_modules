/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:38:27 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/23 22:27:57 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL__H
#define ANIMAL__H

#include <iostream>

#ifdef DEBUG
#	define LOG(str) std::cout << str << std::endl
#else
#	define LOG(str)
#endif
class Animal
{
	protected:
		std::string _type;
	
	public:
		Animal( void );
		Animal( const Animal &copy );
		virtual ~Animal( void );

		Animal 			&operator=(const Animal &rhs );
		std::string		getType( void )	const;
		void			setType( const std::string &type );
		virtual void	makeSound( void ) const;
};

#endif