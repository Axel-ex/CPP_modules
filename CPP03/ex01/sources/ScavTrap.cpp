/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:07:00 by achabrer          #+#    #+#             */
/*   Updated: 2024/04/20 11:34:38 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap ::ScavTrap(void)
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    _hit_point = 100;
    _energy_point = 50;
    _attack_damage = 20;
}

ScavTrap ::~ScavTrap(void)
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap ::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap name constructor called" << std::endl;
    _hit_point = 100;
    _energy_point = 50;
    _attack_damage = 20;
}

ScavTrap ::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap ::operator=(const ScavTrap& rhs)
{
    if (this != &rhs)
    {
        _name = rhs.getName();
        _attack_damage = rhs.getAttackDammage();
        _hit_point = rhs.getHitPoints();
        _energy_point = rhs.getEnergyPoints();
    }
    return (*this);
}

void ScavTrap::guardGate(void) const
{
    std::cout << "ScavTrap " << _name << " is in guardGate mode" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (_energy_point == 0)
    {
        std::cout << "ScavTrap " << _name
                  << " doesn't have enough energy point to attack" << std::endl;
        return;
    }
    if (_hit_point == 0)
    {
        std::cout << "ScavTrap " << _name << " is dead and can't attack"
                  << std::endl;
        return;
    }
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing "
              << _attack_damage << " points of damage!" << std::endl;
    _energy_point--;
}
