/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:47:42 by achabrer          #+#    #+#             */
/*   Updated: 2024/03/12 18:31:13 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.hpp"
#include <iostream>

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

template <typename T>
void	test( const T &c, const T &d, std::string test_type )
{
	T	a = c;
	T 	b = d;

	printBanner(test_type);
	pressEnter();
	
	printBanner("SWAP");
	std::cout << "\nbefore: " <<std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	swap<T>(a, b);
	std::cout << "\nafter: " <<std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	pressEnter();
	
	printBanner("MAX");
	std::cout << max<T>(a, b) << std::endl;
	pressEnter();

	printBanner("MIN");
	std::cout << min<T>(a, b) << std::endl;
	pressEnter();
}


int	main( void )
{
	clearScreen();
	test<int>(42, 24, "INT TEST");
	test<char>('a', 'b', "CHAR TEST");
	test<float>(2.01f, 42.42f, "FLOAT TEST");

	//AMBIGUOUS
	// test<std::string>("hey les boys", "hey les girls", "STRING TEST");

	return (EXIT_SUCCESS);
}
