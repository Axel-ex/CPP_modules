/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:24:21 by achabrer          #+#    #+#             */
/*   Updated: 2024/03/14 11:04:37 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Intern.hpp"


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

void printBanner(const std::string& msg)
{
    const int bannerWidth = 15;
    int padding = std::max(0, (bannerWidth - static_cast<int>(msg.size())) / 2);
    std::cout << "---->";
    std::cout << std::string(padding, ' ') << msg << std::string(padding, ' ');
    std::cout << "<----" << std::endl;
}

void	makeFormTest()
{
	printBanner("Intern test");
	pressEnter();

	Intern		axel;
	AForm		*forms[3];
	Bureaucrat	john("john", 1);

	printBanner("MAKE FORM TEST");
	pressEnter();
	
	try
	{
		for (int i = 0; i < 3; i++)
			forms[i] = axel.makeForm("shrubbery", "whatever");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	printBanner("EXECUTE");
	for (int i = 0; i < 3; i++)
	{
		john.signForm(*forms[i]);
		john.executeForm(*forms[i]);
	}
	pressEnter();

	for (int i = 0; i< 3; i++)
		delete forms[i];
}

void	invalidFormTest()
{
	printBanner("INVALID FORM TEST");
	pressEnter();

	Intern	Axel;

	try
	{
		Axel.makeForm("ndjned", "dede");
	}
	catch (std::exception &e)
	{
		std::cout << RED <<  e.what() << RESET << std::endl;
	}
	pressEnter();
}

int	main( void )
{
	clearScreen();
	makeFormTest();
	invalidFormTest();

	return (EXIT_SUCCESS);
}
