/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:47:44 by achabrer          #+#    #+#             */
/*   Updated: 2024/03/01 11:38:08 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"

void	clearScreen( void )
{
	std::cout << "\033c";
}

void	printBanner( std::string msg )
{
	std::cout << "\t--->" << msg << "<---" << std::endl << std::endl;
}

void	pressEnter( void )
{
	std::cout << "\npress ENTER to continue..." << std::endl;
	std::cin.ignore(1);
	clearScreen();
}

void	subjectTest( void )
{
	printBanner("SUBJECT TEST");
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}

	//exists a constructor for std::stack that accepts std::deque, not std::list
	std::stack<int> s(mstack);
	pressEnter();
}

void myTest( void )
{
	MutantStack<std::string>	s;

	printBanner("MY TEST");
	s.push("hello");
	s.push("my");
	s.push("friends");

	std::deque<std::string>::const_iterator	it;

	for (it = s.cbegin(); it != s.cend(); it++)
	{
		std::cout << *it << std::endl;
		//Impossible
		// *it = "lol";
	}
	pressEnter();

	std::deque<std::string>::iterator	it2;
	for (it2 = s.begin(); it2 != s.end(); it2++)
	{
		*it2 = "lol";
		std::cout << *it2 << std::endl;
	}
}

int	main( void )
{
	clearScreen();
	subjectTest();
	myTest();
	
	return (EXIT_SUCCESS);
}