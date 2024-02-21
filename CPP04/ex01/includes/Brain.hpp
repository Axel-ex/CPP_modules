/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:23:34 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/20 15:34:29 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN__H
#define BRAIN__H

#define NB_IDEAS 100

#include <iostream>

class Brain
{
	private:
		std::string _ideas[NB_IDEAS];

	public:
		Brain( void );
		Brain( const Brain &copy );
		~Brain( void );

		Brain &operator=( const Brain &rhs );

		std::string getIdea(int	index) const;

};

#endif