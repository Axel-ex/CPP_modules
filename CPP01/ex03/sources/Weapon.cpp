/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:09:44 by achabrer          #+#    #+#             */
/*   Updated: 2024/04/13 18:28:06 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string weapon_type) : _type(weapon_type) {}

Weapon::~Weapon(void) {}

void Weapon::setType(std::string new_type) { this->_type = new_type; }

const std::string &Weapon::getType(void) const
{ 
	return (static_cast<const std::string&>(this->_type)); 
}
