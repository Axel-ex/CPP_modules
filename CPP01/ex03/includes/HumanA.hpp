/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:18:28 by achabrer          #+#    #+#             */
/*   Updated: 2024/01/29 11:16:06 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANA_H
#define __HUMANA_H

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();

        void attack(void) const;

    private:
        std::string _name;
        Weapon &_weapon;
};

#endif