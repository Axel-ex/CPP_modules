/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:40:25 by achabrer          #+#    #+#             */
/*   Updated: 2024/01/29 11:30:36 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANB__H
#define __HUMANB__H

#include "Weapon.hpp"

class HumanB
{
    public:
        HumanB(std::string name);
        ~HumanB();

        void attack(void) const;
        void setWeapon(Weapon &weapon);

    private:
        std::string _name;
        Weapon *_weapon;
};

#endif