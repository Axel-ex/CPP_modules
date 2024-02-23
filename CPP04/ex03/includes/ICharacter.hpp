/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:49:07 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/22 10:22:58 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"

class AMateria; 

class ICharacter
{
public:
	virtual ~ICharacter( void ){};
	virtual	const	std::string &getName( void ) const = 0;
	virtual void	equip( AMateria *m ) = 0;
	virtual	void	unequip( int idx) = 0;
	virtual void	use( int idx, ICharacter &target ) = 0;
};

#endif