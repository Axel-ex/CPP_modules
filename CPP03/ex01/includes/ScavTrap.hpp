/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:59:47 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/19 17:08:44 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP__H
#define SCAVTRAP__H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
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