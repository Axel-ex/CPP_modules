/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:16:05 by achabrer          #+#    #+#             */
/*   Updated: 2024/01/26 16:32:20 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE__H
# define __ZOMBIE__H

# include <iostream>


class	Zombie
{
	public:
		Zombie( void );
		~Zombie( void );

		Zombie( std::string name );
		void	announce( void );

	
	private:
		std::string	_name;

};

Zombie 	*newZombie( std::string name );
void	randomChump( std::string name);

#endif