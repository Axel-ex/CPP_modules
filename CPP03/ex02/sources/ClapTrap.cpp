/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:52:36 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/20 12:04:26 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

//CONSTRUCTORS
ClapTrap::ClapTrap( void ) : _name("bob"), _hit_point(10), _energy_point(10),
_attack_damage(0)
{
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hit_point(10),
_energy_point(10), _attack_damage(10)
{
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &copy )
{
	*this = copy;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "Destructor called" << std::endl;
}


//OPERATOR OVERLOAD
ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	if (this != &rhs)
	{
		_name = rhs.getName();
		_hit_point = rhs.getHitPoints();
		_energy_point = rhs.getEnergyPoints();
		_attack_damage = rhs.getAttackDammage();
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &ofs, const ClapTrap &rhs)
{
	std::cout << "name: " << rhs.getName() << std::endl;
	std::cout << "\thit points: " << rhs.getHitPoints() << std::endl;
	std::cout << "\tattack points: " << rhs.getAttackDammage() << std::endl;
	std::cout << "\tenergy points: " << rhs.getEnergyPoints() << std::endl;
	return (ofs);
}

//GETTERS
std::string	ClapTrap::getName( void ) const
{
	return (_name);
}

int	ClapTrap::getAttackDammage( void ) const
{
	return (_attack_damage);
}

int	ClapTrap::getEnergyPoints( void ) const
{
	return (_energy_point);
}

int	ClapTrap::getHitPoints( void ) const
{
	return (_hit_point);
}

//OTHER MEMBER FUNCTIONS
void	ClapTrap::attack( const std::string &target )
{
	if (_energy_point == 0)
	{
		std::cout << "ClapTrap " << _name << " doesn't have enough energy point to attack"
		<< std::endl;
		return ;
	}
	if (_hit_point == 0)
	{
		std::cout << "ClapTrap " << _name << " is dead and can't attack" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
	<< _attack_damage << " points of damage!" << std::endl;
	_energy_point--;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (_hit_point == 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead!"
		<< std::endl;
		return ;	
	}
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of dammage"
	<<std::endl;
	_hit_point -= amount;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	std::cout << "ClapTrap " << _name << " was repaired of " << amount << std::endl;
	_hit_point += amount;
}