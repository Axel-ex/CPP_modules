/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:27:00 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/19 17:01:39 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

int	main(void)
{
	FragTrap john = FragTrap("bob");
	FragTrap leo = FragTrap("leo");
	FragTrap bob;

	std::cout << "INIT JOHN LEO AND BOB" << std::endl;
	std::cout << john << std::endl;
	std::cout << leo << std::endl;
	std::cout << bob << std::endl;

	std::cout << "COPY OVERLOAD" << std::endl;
	bob = leo;
	std::cout << john << std::endl;
	std::cout << leo << std::endl;
	std::cout << bob << std::endl;

	std::cout << "HIGH FIVE?" << std::endl;
	john.highFiveGuys();
	
	return (EXIT_SUCCESS);
}