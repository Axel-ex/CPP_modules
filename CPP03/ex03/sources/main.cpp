/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:27:00 by achabrer          #+#    #+#             */
/*   Updated: 2024/04/20 11:41:20 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamonTrap.hpp"
#include "cstdlib"

void pressEnter(void)
{
    std::cout << "\nPress ENTER to continue...";
    std::cin.ignore(10000, '\n');
    std::cout << "\033c";
}

void printBanner(std::string msg)
{
    std::cout << "----->" << msg << "<-----" << std::endl;
    std::cout << std::endl;
}

int main(void)
{

    printBanner("CREATION");
    DiamondTrap trap = DiamondTrap("Axel");
    DiamondTrap copy = DiamondTrap(trap);
    pressEnter();

    printBanner("ORIGINAL AND COPY");
    std::cout << trap << std::endl << std::endl;
    std::cout << copy << std::endl << std::endl;
    pressEnter();

    printBanner("WHO ARE YOU");
    trap.whoAmI();
    std::cout << std::endl;
    pressEnter();

    printBanner("MEMBER FCTS TEST");
    trap.attack("Denis");
    trap.guardGate();
    trap.highFiveGuys();
    pressEnter();

    return (EXIT_SUCCESS);
}
