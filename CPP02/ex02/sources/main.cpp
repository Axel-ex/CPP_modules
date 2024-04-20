/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:45:35 by achabrer          #+#    #+#             */
/*   Updated: 2024/04/20 10:49:25 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include <iostream>

int main(int argc, char **argv)
{

	try
	{
		if (argc < 3)
			throw std::runtime_error("Enter two valid args");
		float num1 = std::atof(argv[1]);
		float num2 = std::atof(argv[2]);

		Fixed	a = Fixed(num1);
		Fixed	b(num2);

		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << std::endl;

		std::cout << "COMPARISON" << std::endl;
		std::cout << "a > b:\t" << (a > b) << std::endl;
		std::cout << "a <= b:\t" << (a <= b) << std::endl;
		std::cout << "a >= b:\t" << (a >= b) << std::endl;
		std::cout << "a < b:\t" << (a < b) << std::endl;
		std::cout << "a == b:\t" << (a == b) << std::endl;
		std::cout << "a != b:\t" << (a != b) << std::endl;
		std::cout << std::endl;

		std::cout << "OPERATION" << std::endl;
		std::cout << "a + b:\t" << (a + b) << std::endl;
		std::cout << "a - b:\t" << (a - b) << std::endl;
		std::cout << "a * b:\t" << (a * b) << std::endl;
		std::cout << "a / b:\t" << (a / b) << std::endl;
		std::cout << std::endl;

		std::cout << "MIN and MAX" << std::endl;
		std::cout << "min(a,b):\t" << Fixed::min(a, b) << std::endl;
		std::cout << "max(a,b):\t" << Fixed::max(a, b) << std::endl;
		std::cout << "min(a,b):\t" << Fixed::min(static_cast<const Fixed>(a),
	static_cast<const Fixed>(b)) << std::endl; 		std::cout << "max(a,b):\t"
	<< Fixed::max(static_cast<const Fixed>(a), static_cast<const Fixed>(b)) <<
	std::endl; 		std::cout << std::endl;

		std::cout << "INCREMENTS/DECREMENTS" << std::endl;
		std::cout << "b++:\t" << b++ << std::endl;
		std::cout << "++b:\t" << ++b << std::endl;
		std::cout << "b--:\t" << b-- << std::endl;
		std::cout << "--b:\t" << --b << std::endl;

		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (EXIT_SUCCESS);
}

