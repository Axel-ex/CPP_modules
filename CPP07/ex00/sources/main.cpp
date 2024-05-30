/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:47:42 by achabrer          #+#    #+#             */
/*   Updated: 2024/05/30 10:51:22 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.hpp"
#include <iostream>
#include <cstdlib>

void clearScreen(void) { std::cout << "\033c"; }

void pressEnter(void)
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

template <typename T> void test(const T& c, const T& d, std::string test_type)
{
    T a = c;
    T b = d;

    printBanner(test_type);
    pressEnter();

    printBanner("SWAP");
    std::cout << "\nbefore: " << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    swap<T>(a, b);
    std::cout << "\nafter: " << std::endl;
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

void test_equality(void)
{
	int a = 42, b = 42;
	
	printBanner("EQUALITY TEST");
	const int &res = max<int>(a, b);
	std::cout << "max returned the variable: ";
	&res == &a ? std::cout << "a" : std::cout << "b";
	pressEnter();
}

int main(void)
{
    clearScreen();
    test<int>(42, 24, "INT TEST");
    test<char>('a', 'b', "CHAR TEST");
    test<float>(2.01f, 42.42f, "FLOAT TEST");
	test_equality();

    return (EXIT_SUCCESS);
}
