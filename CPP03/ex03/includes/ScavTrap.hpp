/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:59:47 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/20 12:45:56 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP__H
#define SCAVTRAP__H

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( const ScavTrap &copy );
		~ScavTrap( void );

		ScavTrap &operator=(const ScavTrap &rhs);
		void	guardGate( void ) const;
};

std::ostream &operator<<(std::ostream &ofs, const ScavTrap &rhs);

#endif