/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:27:56 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/22 15:33:49 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure( void );
		Cure( const Cure &copy );
		~Cure( void );

		Cure	&operator=( const Cure &rhs );

		void			use( ICharacter &target );
		AMateria		*clone( void )	const;
};

#endif
