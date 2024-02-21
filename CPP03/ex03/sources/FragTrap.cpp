/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:32:25 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/20 12:04:26 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

//CONSTRUCTORS
FragTrap :: FragTrap( void )
{
	std::cout << "FragTrap default constructor called" << std::endl;
	_hit_point = 100;
	_energy_point = 100;
	_attack_damage = 30;
}

FragTrap :: FragTrap( std::string name ) : ClapTrap(name)
{
	std::cout << "FragTrap name constructor called" << std::endl;
	_hit_point = 100;
	_energy_point = 100;
	_attack_damage = 30;
}

FragTrap :: FragTrap( const FragTrap &trap ) : ClapTrap(trap)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap :: ~FragTrap( void )
{
	std::cout << "FragTrap destructor called" << std::endl;
}

//OPERATOR OVERLOADING
FragTrap &FragTrap :: operator=( const FragTrap &trap )
{
	if (this != &trap)
	{
		_name = trap.getName();
		_hit_point = trap.getHitPoints();
		_energy_point = trap.getEnergyPoints();
		_attack_damage = trap.getAttackDammage();
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &ofs, const FragTrap &rhs)
{
	std::cout << "name: " << rhs.getName() << std::endl;
	std::cout << "\thit points: " << rhs.getHitPoints() << std::endl;
	std::cout << "\tattack points: " << rhs.getAttackDammage() << std::endl;
	std::cout << "\tenergy points: " << rhs.getEnergyPoints() << std::endl;
	return (ofs);
}

//MEMBER FUNCTIONS
void FragTrap :: highFiveGuys( void )
{
	std::cout << "HIGH FIVE!" << std::endl;
}