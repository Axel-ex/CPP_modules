/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:42:08 by achabrer          #+#    #+#             */
/*   Updated: 2024/01/29 11:31:15 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB(void) {}

void HumanB::setWeapon(Weapon& weapon) { this->_weapon = &weapon; }

void HumanB::attack(void) const
{
    std::cout << this->_name << " attacks with their "
              << this->_weapon->getType() << std::endl;
}
