/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:25:00 by achabrer          #+#    #+#             */
/*   Updated: 2024/01/26 16:36:21 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int main(int argc, char **argv)
{
    std::string name_1, name_2;

    if (argc < 3)
        return (std::cout << "Enter 2 zombies name" << std::endl, EXIT_SUCCESS);
    name_1 = argv[1];
    name_2 = argv[2];

    std::cout << "ZOMBIE ALLOCATED ON HEAP" << std::endl;
    Zombie *zombie1 = newZombie(name_1);
    zombie1->announce();
    std::cout << std::endl;

    std::cout << "ZOMBIE ALLOCATED ON STACK" << std::endl;
    Zombie zombie2 = Zombie(name_2);
    zombie2.announce();

    return (delete (zombie1), EXIT_SUCCESS);
}