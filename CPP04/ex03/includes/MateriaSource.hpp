/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:43:10 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/22 14:34:58 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "Character.hpp"
#include "Floor.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_source[MAX_ITEMS];
		
	public:
		MateriaSource( void );
		MateriaSource( const MateriaSource &copy );
		~MateriaSource( void );

		MateriaSource &operator=( const MateriaSource &rhs );
		
		void		learnMateria( AMateria *m );
		AMateria	*createMateria( const std::string &type );
		void		displayMateria( int idx, std::ostream &ofs )	const;
};

std::ostream &operator<<( std::ostream &ofs, const MateriaSource &rhs );

#endif