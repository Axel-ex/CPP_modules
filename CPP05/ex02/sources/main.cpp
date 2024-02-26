/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:24:21 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/26 14:14:05 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"


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
}

void	shrubberyFormTest( void )
{
	AForm		*shrub = new ShrubberyCreationForm("home");
	Bureaucrat	axel = Bureaucrat("Axel", 137);

	printBanner("SHRUBBERY");
	pressEnter();

	printBanner("PRINT OBJECTS");
	std::cout << *shrub << std::endl;
	std::cout << axel << std::endl;
	pressEnter();

	printBanner("EXECUTE");
	axel.signForm(*shrub);
	axel.executeForm(*shrub);
	pressEnter();

	delete shrub;
}

void	CopyTest()
{
	ShrubberyCreationForm	shrub = ShrubberyCreationForm("nb1");
	ShrubberyCreationForm	shrub2 = ShrubberyCreationForm("nb2");
	Bureaucrat				axel = Bureaucrat("Axel", 140);

	printBanner("COPY");
	pressEnter();

	printBanner("BEFORE COPY");
	axel.signForm(shrub);
	std::cout << shrub << std::endl;
	std::cout << shrub2 << std::endl;
	pressEnter();

	shrub2 = shrub;
	printBanner("AFTER COPY");
	std::cout << shrub << std::endl;
	std::cout << shrub2 << std::endl;
	pressEnter();
}

void	robotomyFormTest()
{
	Bureaucrat			axel("Axel", 1);
	RobotomyRequestForm	form(axel.getName());

	printBanner("ROBOTOMY");
	pressEnter();

	printBanner("PRINT OBJECTS");
	std::cout << form << std::endl;
	std::cout << axel << std::endl;
	pressEnter();

	printBanner("EXECUTE");
	axel.signForm(form);
	for (int i = 0; i < 4; i++)
		axel.executeForm(form);
	pressEnter();
}

void	presidentialPardonTest()
{
	PresidentialPardonForm	form("Axel");
	Bureaucrat				axel("Axel", 1);

	printBanner("PRESIDENTIAL PARDON");
	pressEnter();

	printBanner("PRINT OBJECTS");
	std::cout << form << std::endl;
	std::cout << axel << std::endl;
	pressEnter();

	printBanner("EXECUTE");
	axel.signForm(form);
	axel.executeForm(form);
	pressEnter();
}

void	limitsTest()
{
	PresidentialPardonForm	form("Axel");
	Bureaucrat				axel("Axel", 130);

	printBanner("LIMITS TEST");
	pressEnter();

	printBanner("PRINT OBJECTS");
	std::cout << form << std::endl;
	std::cout << axel << std::endl;
	pressEnter();

	printBanner("EXECUTE");
	axel.executeForm(form);
	pressEnter();

	printBanner("EXECUTE UNSIGNED");
	while (axel.getGrade() > 5)
		axel.incrementGrade();
	axel.executeForm(form);
	pressEnter();


}

int	main( void )
{
	clearScreen();
	shrubberyFormTest();
	robotomyFormTest();
	presidentialPardonTest();
	CopyTest();
	limitsTest();
	return (EXIT_SUCCESS);
}