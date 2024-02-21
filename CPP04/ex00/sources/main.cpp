/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:00:51 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/20 15:07:30 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

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
	
	Animal	meta = Animal();
	Cat		cat = Cat();
	Dog		dog = Dog();
	
	pressEnter();

	printBanner("METHODS");
	std::cout << "meta says: \n"; meta.makeSound(); std::cout << std::endl;
	std::cout << "Cat says: "; cat.makeSound(); std::cout << std::endl;
	std::cout << "Dog says: "; dog.makeSound(); std::cout << std::endl;
	pressEnter();

	printBanner("COPIES");
	Cat copy_cat = cat;
	Dog copy_dog = dog;
	pressEnter();

	printBanner("WITH POINTER");
	Animal *ptr = new Cat();
	std::cout << "The cat should do: "; ptr->makeSound();
	std::cout << std::endl;
	pressEnter();

	printBanner("WRONG ANIMAL");
	WrongAnimal *ptr2 = new WrongCat();
	std::cout << "The cat should do: "; ptr2->makeSound();
	std::cout << std::endl;

	delete ptr;
	delete ptr2;
	return (EXIT_SUCCESS);
}