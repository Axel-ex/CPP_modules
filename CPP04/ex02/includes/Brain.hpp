/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:23:34 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/24 10:16:41 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN__H
#define BRAIN__H

#define MAX_IDEAS 100

#include <iostream>

class Brain
{
	private:
		std::string _ideas[MAX_IDEAS];
		int			_nb_ideas;

	public:
		Brain( void );
		Brain( const Brain &copy );
		~Brain( void );

		Brain &operator=( const Brain &rhs );

		void		setIdea( const std::string &idea, int index );
		std::string getIdea( int index )	const;
		int			getNbIdea( void )		const;
		void		print( void )			const;

};

#endif