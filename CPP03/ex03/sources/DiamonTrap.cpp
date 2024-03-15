/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamonTrap.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:36:55 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/20 12:08:03 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamonTrap.hpp"

// CONSTRUCTORS
// the last constructor call overrides the attributes: attributes wil here be
// set to the values of the ScavTrap. Here by default all the constructor will
// called anyway
DiamondTrap ::DiamondTrap(void) : ClapTrap(), FragTrap(), ScavTrap()
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
    _name = "";
    _hit_point = 100;
    _attack_damage = 30;
    ClapTrap::_name = _name + "_clap_name";
}

DiamondTrap ::DiamondTrap(std::string name)
    : ClapTrap(name), FragTrap(name), ScavTrap(name), _name(name)
{
    _hit_point = 100;
    _attack_damage = 30;
    ClapTrap::_name = name + "_clap_name";
}

DiamondTrap ::DiamondTrap(const DiamondTrap& trap)
    : ClapTrap(trap), FragTrap(trap), ScavTrap(trap)
{
    *this = trap;
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap ::~DiamondTrap(void)
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

// OPERATOR OVERLOAD
std::ostream& operator<<(std::ostream& ofs, const DiamondTrap& rhs)
{
    std::cout << "name: " << rhs.getName() << std::endl;
    std::cout << "\thit points: " << rhs.getHitPoints() << std::endl;
    std::cout << "\tattack points: " << rhs.getAttackDammage() << std::endl;
    std::cout << "\tenergy points: " << rhs.getEnergyPoints() << std::endl;
    return (ofs);
}

DiamondTrap& DiamondTrap ::operator=(const DiamondTrap& rhs)
{
    if (this != &rhs)
    {
        _name = rhs.getName();
        _hit_point = rhs.getHitPoints();
        _attack_damage = rhs.getAttackDammage();
        _energy_point = rhs.getEnergyPoints();
    }
    return (*this);
}

// MEMBER FUNCTIONS
void DiamondTrap ::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

std::string DiamondTrap ::getName(void) const { return (_name); }

void DiamondTrap ::whoAmI(void) const
{
    std::cout << "My name is: " << _name << std::endl;
    std::cout << "My claptrap is called: " << ClapTrap::getName() << std::endl;
}