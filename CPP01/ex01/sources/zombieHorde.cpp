/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:44:34 by achabrer          #+#    #+#             */
/*   Updated: 2024/01/26 19:09:05 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    if (N < 0)
        return (NULL);

    Zombie* zombie_horde = new Zombie[N];
    for (int i = 0; i < N; i++)
        zombie_horde[i].setName(name);

    return (zombie_horde);
}