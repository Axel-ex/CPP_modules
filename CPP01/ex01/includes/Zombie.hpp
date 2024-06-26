/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:16:05 by achabrer          #+#    #+#             */
/*   Updated: 2024/04/13 17:57:36 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE__H
#define __ZOMBIE__H

#include <iostream>
#include <cstdlib>

class Zombie
{
    public:
        Zombie(void);
        ~Zombie(void);
        Zombie(std::string name);

        void announce(void);
        void setName(std::string name);

    private:
        std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
