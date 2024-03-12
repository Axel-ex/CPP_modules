/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:08:55 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/28 10:13:23 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/functions.hpp"

void	clearScreen( void )
{
	std::cout << "\033c";
}

void	pressEnter( void )
{
	std::cout << "\nPress ENTER to continue...";
	std::cin.ignore(10000, '\n');
}

int	main()
{
	Base	*ptr[5];

	std::srand(time(NULL));
	clearScreen();

	std::cout << "Identify pointers type" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		ptr[i] = generate();
		identify(ptr[i]);
	}
	pressEnter();

	std::cout << std::endl << "Identify reference type" << std::endl;
	for (int i = 0; i < 5; i++)
		identify(*ptr[i]);
	pressEnter();
	
	for (int i = 0; i < 5; i++)
		delete	ptr[i];
}