/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:09:44 by achabrer          #+#    #+#             */
/*   Updated: 2024/01/29 11:38:48 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string weapon_type) : _type(weapon_type) {}

Weapon::~Weapon(void) {}

void Weapon::setType(std::string new_type) { this->_type = new_type; }

std::string Weapon::getType(void) const { return (this->_type); }