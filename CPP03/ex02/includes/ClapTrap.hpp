/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:45:16 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/20 12:04:27 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP__H
#define CLAPTRAP__H

#include <iostream>

class ClapTrap
{
    public:
        ClapTrap(void);
        ClapTrap(std::string name);
        virtual ~ClapTrap(void);
        ClapTrap(const ClapTrap& copy);
        ClapTrap& operator=(const ClapTrap& rhs);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string getName(void) const;
        int getHitPoints(void) const;
        int getEnergyPoints(void) const;
        int getAttackDammage(void) const;

    protected:
        std::string _name;
        int _hit_point;
        int _energy_point;
        int _attack_damage;
};

std::ostream& operator<<(std::ostream& ofs, const ClapTrap& rhs);

#endif