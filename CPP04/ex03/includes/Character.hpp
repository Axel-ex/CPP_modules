/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:29:53 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/22 14:36:39 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "Floor.hpp"

#define MAX_ITEMS 4

class Character : public ICharacter
{
	private:
		AMateria 	*_inventory[MAX_ITEMS];
		std::string	_name;

	public:
		Character( void );
		Character( const std::string &name );
		Character( const Character &copy );
		~Character( void );

		Character	&operator=( const Character &rhs );

		const std::string	&getName( void )	const;
		void		equip( AMateria *m );
		void		unequip( int idx );
		void		use( int idx, ICharacter &target );
};

#endif