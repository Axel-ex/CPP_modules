/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:56:29 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/22 16:47:19 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Character.hpp"
#include "../includes/MateriaSource.hpp"

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

void	subjectTest( void )
{
	printBanner("SUBJECT TEST");
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	pressEnter();
}

void	limitsTest( void )
{
	clearScreen();
	printBanner("INIT");
	MateriaSource *source = new MateriaSource();
	source->learnMateria(new Ice());
	source->learnMateria(new Cure());
	pressEnter();

	printBanner("5 MATERIAS");
	AMateria *mat;
	for (int i = 0; i < 7; i++)
	{
		mat = source->createMateria("ice");
		source->learnMateria(mat);
	}
	pressEnter();

	printBanner("DISPLAY THE SOURCE");
	std::cout << *source << std::endl;
	pressEnter();
	
	printBanner("DISPLAY THE FLOOR");
	Floor::displayList();
	pressEnter();
	
	printBanner("EXIT");
	delete source;
}

// void	deepCopyTest()
// {

// }

int	main(void)
{
	subjectTest();
	limitsTest();
	// deepCopyTest();
	return (EXIT_SUCCESS);
}