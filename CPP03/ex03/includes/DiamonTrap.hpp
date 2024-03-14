/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamonTrap.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:27:12 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/20 12:07:52 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP__H
#define DIAMONDTRAP__H

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    public:
        DiamondTrap(void);
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap &trap);
        ~DiamondTrap(void);

        DiamondTrap &operator=(const DiamondTrap &trap);

        void attack(const std::string &target);
        void whoAmI(void) const;
        std::string getName(void) const;

    private:
        std::string _name;
};

std::ostream &operator<<(std::ostream &ofs, const DiamondTrap &rhs);

#endif