/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:11:56 by achabrer          #+#    #+#             */
/*   Updated: 2024/03/12 18:33:25 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"
#include <deque>
#include <list>

void	clearScreen( void )
{
	std::cout << "\033c";
}

void	pressEnter( void )
{
	std::cout << "press ENTER to continue..." << std::endl;
	std::cin.ignore(1);
	clearScreen();
}

template<typename T>
void	fillContainer(T &cont)
{
    for (int i = 0; i < 100; i++)
		cont.push_back(rand() % 100);
}

template<typename T>
void	basicTest(T &cont , std::string test_name)
{
	std::cout << "\t" << test_name << std::endl << std::endl;
	fillContainer(cont);
	try
	{
		int pos = easyfind(cont, 42);
		std::cout << "Found 42 at the index [" << pos << "]" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	pressEnter();
}

int	main( void )
{
	std::srand(time(NULL));
	std::vector<int>		vect;
	std::list<int>			list;
	std::deque<int>			queue;

	clearScreen();
	basicTest<std::vector<int> >(vect, "VECTOR");
	basicTest<std::list<int> >(list, "LIST");
	basicTest<std::deque<int> >(queue, "QUEUE");

	return (EXIT_SUCCESS);
}
