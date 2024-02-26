/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:00:51 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/24 10:47:33 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include <iomanip>

void	clearScreen( void )
{
	std::cout << "\033c";
}

void	pressEnter( void )
{
	std::cout << "\nPress ENTER to continue...";
	std::cin.ignore(10000, '\n');
	clearScreen();
}

void	printBanner( const std::string &msg )
{
	std::cout << "----->" << std::setw(10) << msg << "<-----" << std::endl;
	std::cout << std::endl;
}

void	basicTest( void )
{
	printBanner("BASIC TESTS");
	pressEnter();

	printBanner("CREATION");
	Animal	*ptr[3] = {new Cat(), new Cat(), new Dog()};
	pressEnter();

	printBanner("METHOD make");
	for (int i = 0; i < 3 ; i++)
		ptr[i]->makeSound();
	pressEnter();

	printBanner("DELETION");
	for (int i = 0; i < 3; i++)
		delete ptr[i];
	pressEnter();
}

void	brainTest( void )
{
	printBanner("BRAIN TEST");
	pressEnter();

	printBanner("SETTING IDEAS");
	Cat cat = Cat();
	for (int i = 0; i < 5; i++)
		cat.getBrain()->setIdea("*thinking about food*", i);
	pressEnter();
	
	printBanner("DISPLAY OBJECT");
	std::cout << cat << std::endl;
	pressEnter();

	printBanner("BRAIN LIMITS");
	try
	{
		cat.getBrain()->setIdea("Out limits", 101);
	}
	catch (std::exception &e)
	{
		std::cout << "EXCEPTION CAUGHT" << std::endl;
		std::cout << e.what() << std::endl;
	}
	pressEnter();

	printBanner("DESTRUCTION");
}

int	main( void )
{
	clearScreen();
	basicTest();
	brainTest();

	return (EXIT_SUCCESS);
}