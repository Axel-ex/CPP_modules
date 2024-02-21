/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:00:51 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/21 10:19:00 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

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
	std::cout << "----->" << msg << "<-----" << std::endl;
	std::cout << std::endl;
}

int	main(void)
{
	clearScreen();
	
	// printBanner("CAT CREATION");
	// Cat		*cat = new Cat();
	// pressEnter();

	// printBanner("CAT COPY");
	// Cat		*chat = new Cat(*cat);
	// pressEnter();

	// printBanner("DOG CREATION");
	// Dog		*dog = new Dog();
	// pressEnter();

	// printBanner("DESTRUCTORS");
	// delete cat; delete dog; delete chat;
	// pressEnter();

	printBanner("ARRAY OF CATS AND DOGS");
	Animal	animals[10];
	for (int i = 0; i < 5; i++)
		animals[i] = Cat();
	for (int i = 5; i < 10; i++)
		animals[i] = Dog();
	pressEnter();

	printBanner("METHOD CALL");
	for (int i = 0; i < 10; i++)
		animals[i].makeSound();
	pressEnter();

	printBanner("DESTRUCTORS");
	
	return (EXIT_SUCCESS);
}