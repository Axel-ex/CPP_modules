/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:40:56 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/21 09:17:41 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT__H
#define CAT__H

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat( void );
		Cat( const Cat &copy );
		~Cat( void );
		
		Cat &operator=( const Cat &rhs );

		void	makeSound( void )	const;
		Brain	getBrain( void )	const;

		private:
			Brain *_brain;
};

#endif