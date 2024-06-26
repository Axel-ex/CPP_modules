/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:05:34 by achabrer          #+#    #+#             */
/*   Updated: 2024/04/13 18:25:57 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON__H
#define __WEAPON__H

#include <iostream>

class Weapon
{
    public:
        Weapon(std::string weapon_type);
        ~Weapon(void);

        void setType(std::string new_type);
        const std::string &getType(void) const;

    private:
        std::string _type;
};

#endif
