/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:00:51 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/21 15:42:39 by achabrer         ###   ########.fr       */
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
	// printBanner("ARRAY OF CATS AND DOGS");
	// Animal	*animals[10];
	// for (int i = 0; i < 5; i++)
	// 	animals[i] = new Cat();
	// for (int i = 5; i < 10; i++)
	// 	animals[i] = new Dog();
	// pressEnter();

	// printBanner("METHOD CALL");
	// for (int i = 0; i < 10; i++)
	// 	animals[i]->makeSound();
	// pressEnter();

	// printBanner("DESTRUCTORS");
	// for (int i = 0; i < 10; i++)
	// 	delete animals[i];
	// pressEnter();
	
	printBanner("COPY TEST");
	Cat *cat1 = new Cat();
	for (int i = 0; i < 5; i++)
		cat1->getBrain().setIdea("lol", i);
	Cat *cat2 = new Cat(*cat1);
	pressEnter();

	printBanner("ACCESS THE BRAIN");
	delete cat1;
	for (int i = 0; i < 5; i++)
		std::cout << cat2->getBrain().getIdea(i) << std::endl;
	pressEnter();

	printBanner("REPLACE EXISTING BY COPY");
	Cat *cat3 = new Cat();
	cat3->getBrain().setIdea("hey", 0);
	*cat3 = *cat2;
	pressEnter();

	delete cat3; delete cat2;
	return (EXIT_SUCCESS);
}