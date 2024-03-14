/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:27:00 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/19 16:39:07 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

int main(void)
{
    ScavTrap bob = ScavTrap();
    ScavTrap ken;

    std::cout << "INIT BOB SCAVTRAP" << std::endl;
    std::cout << bob << std::endl;

    std::cout << "COPY OVERLOAD" << std::endl;
    ken = ScavTrap(bob);
    std::cout << ken << std::endl;

    std::cout << "COPY CONSTRUCTOR" << std::endl;
    ScavTrap lenny = ScavTrap(bob);
    std::cout << lenny << std::endl;

    return (EXIT_SUCCESS);
}