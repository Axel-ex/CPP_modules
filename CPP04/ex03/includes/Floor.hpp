/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:36:56 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/23 09:40:15 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_HPP
#define FLOOR_HPP

#include "AMateria.hpp"

struct MateriaList
{
	AMateria	*materia;
	MateriaList	*next;
};

/**
 * @brief Singleton class: Floor can't be instanciated more than once. The class globally 
 * keeps track of pointers that are not fitting in the storage of the MateriaSource or the
 * Character. (member fcts can be called from anywhere without manually having to
 * create an instance)
 * 
 */
class Floor
{
	private:
		MateriaList *_materia_list;
		Floor( const Floor&) = delete;
		Floor( void );
		~Floor( void );

		Floor &operator=(const Floor&) = delete;
		
		void			pushFront( AMateria *materia );
		void			deleteMaterias( void );
		void			Idisplaylist( void );

		static Floor	&getInstance( void );
	
	public:
		static void	dropMateria( AMateria *materia );
		static void	displayList( void );
};

#endif