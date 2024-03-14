/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:27:00 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/19 11:47:22 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main(void)
{
    ClapTrap bob = ClapTrap("bob");
    ClapTrap ken;

    for (int i = 0; i < 6; i++)
    {
        bob.attack("ken");
        bob.takeDamage(i);
        std::cout << bob << std::endl;
    }
    std::cout << "\n\t--- COPY OF BOB ---\n" << std::endl;
    ken = bob;
    bob.beRepaired(20);
    std::cout << bob << std::endl;
    std::cout << ken << std::endl;
}