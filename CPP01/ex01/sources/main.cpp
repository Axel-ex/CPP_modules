/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:25:00 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/15 09:40:54 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

bool	isValidNb( std::string s )
{
	for (size_t i = 0; i < s.length(); i++)
	{
		if (!isdigit(s[i]))
			return (false);
	}
	return (true);
}

int	main( int argc, char **argv )
{
	int			size;

	if (argc < 3)
		return (std::cout << "Enter a nb of zombies and a name" << std::endl, EXIT_FAILURE);
	if (!isValidNb(argv[1]))
		return (std::cout << "Enter a valid size" << std::endl, EXIT_FAILURE);
	try
	{
		size = std::stoi(argv[1]);
	}	
	catch (std::out_of_range)
	{
		std::cout << "Enter a value in the integer range" << std::endl;
		exit(EXIT_FAILURE);
	}
	Zombie *zombie_horde = zombieHorde(size, argv[2]);
	if (!zombie_horde)
		return (EXIT_FAILURE);
	for (int i = 0; i < size; i++)
		zombie_horde[i].announce();
	delete[] zombie_horde;
	return (EXIT_SUCCESS);
}